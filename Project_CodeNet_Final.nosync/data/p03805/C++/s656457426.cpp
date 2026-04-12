#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int vis[9];
vector <vector<int> > arr(10);
int cnt, N, M;
void dfs(int src)
{
    vis[src]=1;
    for(int j=0;j<arr[src].size();j++)
    {
        if(vis[arr[src][j]]==0)
            dfs(arr[src][j]);

    }
    cnt++;
    for(int i=1;i<=N;i++)
        if(vis[i]!=1)
        {
            cnt--;
            break;
        }
    //cout << src << " ";
    vis[src]=0;
}

int main()
{
    cin>>N>>M;
    cnt=0;
    memset(vis,0,sizeof vis);
    int x, y;
    for(int i=0;i<M;i++)
    {
        cin>>x>>y;
        arr[x].pb(y);
        arr[y].pb(x);
    }
    dfs(1);
    cout << cnt << endl;
    return 0;
}
