#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int g[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            g[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    int P[N];
    for (int i = 0; i < N; i++)
    {
        P[i] = i;
    }
    int ans = 0;
    do
    {   
        bool is_path = true;
        for (int i = 0; i < N-1; i++)
        {
            if(P[0]!=0)
            {
                is_path = false;
                break;
            }
            if(g[P[i]][P[i+1]]!=1)
            {
                is_path = false;
                break;
            }
        }
        if(is_path)
        {
            ans++;
        }
    } while (next_permutation(P, P+N));
    cout << ans << endl;
    
}
