/******************************************************************************

    manjaelcoder 05.01.2022

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DIM 2
#define N 1000
#define K 5


typedef struct{
    float fv[DIM];
    float dis;
    int id;
    int kId;
}Point;

float distance_euclidean(float p1[], float p2[], int length);
void random_vector_float(float vector[], int length, float min, float max);
void print_array(float * arr, int length);

void kmeans(Point * centroids, Point * points);
void compute_centroids(int assignments[], Point * centroids, Point * points);


int main(int argc, char *argv[])
{
    srand(123);    
    
    Point centroids[K];
    Point points[N];
    
    for(int i = 0; i<K; i++){
        random_vector_float(centroids[i].fv,DIM,0,1);
    }

    for(int i = 0; i<N; i++){
        random_vector_float(points[i].fv,DIM,0,1);
    }
    
    
    for(int i = 0; i<K; i++){
        print_array(centroids[i].fv,DIM);
    }
    
    printf("\n");
    for(int i = 0; i < K; i++)
    {
        for(int j=0;j<DIM;j++)
            printf("%.2f, ", centroids[i].fv[j]);
        printf("\n");
    }
    
    kmeans(centroids, points);
    
    // for(int i=0;i<N;i++)
    //     printf("%d\n",points[i].kId);

    return 0;
}


void kmeans(Point centroids[], Point points[]){
    int clusterChanged = 1;
    float minD, tmpD;
    int minK;
    
    int assign[N]={-1};
    int iteration=0;
    while(clusterChanged){
        clusterChanged = 0;
        for(int i=0;i<N;i++){ //for all points
            minD = distance_euclidean(centroids[0].fv,points[i].fv, DIM);
            minK=0;
            for(int j=1; j<K;j++){
                tmpD=distance_euclidean(centroids[j].fv,points[i].fv, DIM);
                if(tmpD < minD){
                    minD=tmpD; minK=j;
                }
            }
            if (assign[i] != minK){ clusterChanged = 1;}
            assign[i]=minK;
            points[i].kId=minK;
            points[i].dis=minD;
            points[i].id=i;
            
        }
        printf("interation %d:\n", iteration++);
        compute_centroids(assign, centroids, points);
    }

}

void compute_centroids(int assignments[], Point centroids[], Point points[]){
    float sum[K][DIM];
    int count[K];
    
    for(int i=0; i<N;i++){
        for(int j=0;j<DIM;j++){
            sum[assignments[i]][j] += points[i].fv[j];
        }
        count[assignments[i]]++;
    }
    
    for(int i=0; i<K; i++){
        for(int j=0; j<DIM; j++){
            centroids[i].fv[j]=sum[i][j] / count[i];
            
        }
    }
       
}

float distance_euclidean(float p1[], float p2[], int length){
    float ssum = 0.0;
    
    for(int i=0;i<length;i++){
        ssum+=pow(p1[i]-p2[i],2);
    }
    
    return sqrt(ssum);
}


void random_vector_float(float vector[], int length, float min, float max)
{
    float rval, val_scaled;
    for(int i=0; i<length;i++){
            rval = rand() / (float) RAND_MAX; /* [0, 1.0] */
            vector[i] = min + rval * (max - min);      /* [min, max] */
    }
        
}



void print_array(float * arr, int length)
{
    printf("\nPrinting array: ");
    for(int i = 0; i < length; i++)
    {
        printf("%.2f, ", arr[i]);
    }
}
