
#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void BFS(int start, int target) {
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        if (current == target)
            found = 1;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    if (found)
        printf("\nFile found using BFS.\n");
    else
        printf("\nFile not found using BFS.\n");
}

void DFS(int current, int target, int *found) {
    visited[current] = 1;
    printf("%d ", current);

    if (current == target)
        *found = 1;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i])
            DFS(i, target, found);
    }
}

int main() {
    int start, target;

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Enter a number between 1 and 10.\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    printf("Enter file to search (0 to %d): ", n - 1);
    scanf("%d", &target);

    if (start < 0 || start >= n ||
        target < 0 || target >= n) {
        printf("Invalid node number.\n");
        return 0;
    }

    BFS(start, target);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int found = 0;
    printf("\nDFS Traversal: ");
    DFS(start, target, &found);

    if (found)
        printf("\nFile found using DFS.\n");
    else
        printf("\nFile not found using DFS.\n");

    return 0;
}
