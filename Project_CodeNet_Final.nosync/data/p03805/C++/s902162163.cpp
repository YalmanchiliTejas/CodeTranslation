#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;cin >> N >> M;
    vector<vector<int>> graph(N,vector<int> (N,0));
    int u,v;
    for (int i=0;i<M;i++)
    {
        cin >> u >>v;
        u--;v--;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    vector<int> num(N-1);
    for (int i=1;i<N;i++) num[i-1]=i;
    int ans=0;
    bool can=true;
    do
    {
        can=true;
        if (graph[0][num[0]]==0) can=false;
        else
        {
            for (int i=0;i<N-2;i++)
            {
                if (graph[num[i]][num[i+1]]==0)
                {
                    can=false;
                    break;
                }
            }
            if (can) ans++;
        }
    }while (next_permutation(num.begin(),num.end()));
    cout << ans << endl;
    return 0;
}