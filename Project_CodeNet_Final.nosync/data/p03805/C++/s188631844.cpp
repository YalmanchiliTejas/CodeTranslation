#include <bits/stdc++.h>
using namespace std;

const int nmax = 8;
bool graph[nmax][nmax];

int main()
{

    int n, m;
    cin >> n >> m;
    for (auto i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a][b] = graph[b][a] = true;
    }

    int node[n];
    for (auto i = 0; i < n; i++)
    {
        node[i] = i;
    }

    int ans = 0;

    do
    {
        int num = 0;
        for (auto i = 0; i < n-1; i++)
        {
            if(graph[node[i]][node[i+1]]){
                num += 1;
            }
        }

        if(num == n-1){
            ans += 1;
        }
        
    } while (next_permutation(node + 1, node + n));
    cout << ans << endl;
}