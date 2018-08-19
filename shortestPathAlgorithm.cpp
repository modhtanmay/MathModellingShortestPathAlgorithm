// C program for Dijkstra's single
// source shortest path algorithm.
// The program is for adjacency matrix
// representation of the graph.
#include <stdio.h>
#include <limits.h>

// Number of vertices
// in the graph
#define V 21

// A utility function to find the
// vertex with minimum distance
// value, from the set of vertices
// not yet included in shortest
// path tree
int minDistance(int dist[],
                bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false &&
                   dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest
// path from source to j
// using parent array
void printPath(int parent[], int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}

// A utility function to print
// the constructed distance
// array
int printSolution(int dist[], int n,
                      int parent[])
{
    int src = 0;
    printf("Vertex              Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        printf("\n%d -> %d             %d\t\t%d ",
                      src, i, dist[i], src);
        printPath(parent, i);
    }
    printf("\n");
}

// Funtion that implements Dijkstra's
// single source shortest path
// algorithm for a graph represented
// using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{

    // The output array. dist[i]
    // will hold the shortest
    // distance from src to i
    int dist[V];

    // sptSet[i] will true if vertex
    // i is included / in shortest
    // path tree or shortest distance
    // from src to i is finalized
    bool sptSet[V];

    // Parent array to store
    // shortest path tree
    int parent[V];

    // Initialize all distances as
    // INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex
    // from itself is always 0
    dist[src] = 0;

    // Find shortest path
    // for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance
        // vertex from the set of
        // vertices not yet processed.
        // u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex
        // as processed
        sptSet[u] = true;

        // Update dist value of the
        // adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is
            // not in sptSet, there is
            // an edge from u to v, and
            // total weight of path from
            // src to v through u is smaller
            // than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // print the constructed
    // distance array
    printSolution(dist, V, parent);
}

// Driver Code
int main()
{
    // Math model graph
    int graph[V][V] = {
	 // 0 1 2 3 4 5 6 7 8 9 1011121314151617181920
        {0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//0
        {5,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8},//1
        {0,2,0,5,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//2
        {0,0,5,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//3
        {0,0,0,5,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//4
        {0,0,0,0,2,0,5,0,0,0,8,0,0,0,0,0,0,0,0,0,0},//5
        {0,0,4,0,0,5,0,3,0,0,8,0,0,0,0,0,0,0,0,2,0},//6
        {0,0,0,0,0,0,3,0,2,0,0,0,0,0,0,5,0,0,0,0,0},//7
        {0,0,0,0,0,0,0,2,0,3,0,0,0,1,0,0,0,0,0,0,0},//8
        {0,0,0,0,0,0,0,0,3,0,1,6,0,0,0,0,0,0,0,0,0},//9
        {0,0,0,0,0,8,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},//10
        {0,0,0,0,0,0,0,0,0,6,0,0,2,0,0,0,0,0,0,0,0},//11
        {0,0,0,0,0,0,0,0,0,0,0,2,0,6,0,0,0,0,0,0,0},//12
        {0,0,0,0,0,0,0,0,1,0,0,0,6,0,3,0,0,0,0,0,0},//13
        {0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,6,0,0,0,0,0},//14
        {0,0,0,0,0,0,0,5,0,0,0,0,0,0,6,0,2,0,0,0,0},//15
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,3,0,0,0},//16
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1,0,0},//17
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1},//18
        {0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,4,0,0,1,0,0},//19
        {0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},//20
                             };

    dijkstra(graph, 0);
    return 0;
}
