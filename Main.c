
#include <stdio.h>
#include <string.h>

#define N 6

char *files[N] = {
    "Main",
    "Documents",
    "Pictures",
    "Notes",
    "Photos",
    "Downloads"
};

int graph[N][N] = {
    {0,1,1,0,0,0},
    {1,0,0,1,1,0},
    {1,0,0,0,1,0},
    {0,1,0,0,0,0},
    {0,1,1,0,0,0},
    {0,0,0,0,0,0}
};

int visited[N];

void BFS(int start) {
    int queue[N], front = 0, rear = 0;

    for(int i = 0; i < N; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while(front < rear) {
        int current = queue[front++];
        printf("%s ", files[current]);

        for(int i = 0; i < N; i++) {
            if(graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void DFS(int node) {
    visited[node] = 1;
    printf("%s ", files[node]);

    for(int i = 0; i < N; i++) {
        if(graph[node][i] && !visited[i])
            DFS(i);
    }
}

int main() {
    int start = 0;
    int search = 3;

    printf("FILE SYSTEM USING BFS AND DFS\n");

    printf("\nAvailable Files:\n");
    for(int i = 0; i < N; i++)
        printf("%d. %s\n", i, files[i]);

    BFS(start);

    printf("\n");

    for(int i = 0; i < N; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);

    printf("\n\nSearching for: %s\n", files[search]);

    if(visited[search])
        printf("File Found!\n");
    else
        printf("File Not Found!\n");

    return 0;
}
