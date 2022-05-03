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

