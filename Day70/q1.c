#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge
struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge* edges, int source) {
    int dist[n];
    
    // Step 1: Initialize distances from source to all other vertices as infinity
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;

    // Step 2: Relax edges |V| - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }

    printf("Shortest distances from vertex %d:\n", source);
    for (int i = 0; i < n; i++)
        printf("Vertex %d: %d\n", i, dist[i]);
}

int main() {
    int n = 5; // Number of vertices
    int m = 8; // Number of edges
    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(n, m, edges, 0);

    return 0;
}
