#include <iostream>
using namespace std;
int i, j, k, a, b, v, u, n, ne = 1;
int low, mincost = 0, cost[10][10];
int visited[10] = {0};
int main()
{
    cout << "Prims algorithm\n";
    cout << "\nEnter number of vertices:\t";
    cin >> n;
    cout << "\nEnter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    visited[1] = 1;
    // printf("\nThe edges of Minimum Cost spanning tree are:\t");
    while (ne < n)
    {
        for (i = 1, low = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < low)
                {
                    if (visited[i] != 0)
                    {
                        low = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            cout << "\n edge cost= " << low;
            mincost += low;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << "\nMinimum Cost= " << mincost;
    return 0;
}