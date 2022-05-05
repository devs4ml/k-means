/******************************************************************************

    manjaelcoder 05.01.2022

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "kmeans.h"

#undef  DIM
#define  DIM 20

#undef  N
#define  N 10000

#undef  K
#define  K 10


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

