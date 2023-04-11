#include <iostream>

using namespace std;

int shortest(int, int);
int cost[10][10], dist[20], i, j, n, k, m, S[20], v, totcost, path[20], p;
int main()
{
    int c;
    cout << "Enter no of vertices: ";
    cin >> n;

    cout << "Enter No of edges: ";
    cin >> m;

    cout << "Enter Cost of Edge\n";
    
    for(k = 1; k <= m; k++)
    {
        cin >> i >> j >> c;
        cost[i][j] = c;
    }

    for(i = 1; i < n; i++)
    {
        for(j = 1; j < n; j++)
        {
            if(cost[i][j] == 0)
            {
                cost[i][j] = 31999;
            }
        }
    }

    cout << "Enter Initial Vertex";
    cin >> v;
    cout << v << endl;
    shortest(v, n);
}

int shortest(int v, int n)
{
    int min;
    for(i = 1; j <= n; i++)
    {
        S[i] = 0;
        dist[i] = cost[v][i];
    }
    path[++p] = v;
    S[v] = 1;
    dist[v] = 0;

    for(i = 2; i <= n; i++)
    {
        k = 1;
        min = 31999;
    }

    for(j = 1; j <= n; j++)
    {
        if(dist[j] < min && S[j] != 1)
        {
            min = dist[j];
            k = j;
        }
    }
    
    if(cost[v][k] <= dist[k])
    {
        p = 1;
        path[++p] = k;
    }

    for(j = 1; j <= p; j++)
    {
        cout << path[j];
        cout << endl;
    }

    S[k] = 1;

    for(j = 1; j <= n; j++)
    {
        if(cost[k][j] != 31999 && dist[j] >= dist[k] + cost[k][j] && S[j]!=1)
        {
            dist[j] = dist[k] + cost[k][j];
        }
    }
}
