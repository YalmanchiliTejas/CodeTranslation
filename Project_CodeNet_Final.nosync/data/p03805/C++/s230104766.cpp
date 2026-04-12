#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,m,a,b,i;
    cin>>n>>m;
    int Graph[n+1][n+1];
    memset(Graph,0,sizeof(Graph));
    for (i=0;i<m;i++)
    {
        cin>>a>>b;
        Graph[a][b]++;
        Graph[b][a]++;
    }
    int path[n];
    for (i=0;i<n;i++)
        path[i]=i+1;
    ll ans=0;
    do{
        bool flag=true;
        if (path[0]!=1)
            continue;
        for (i=0;i<n-1;i++)
        {
            if (Graph[path[i]][path[i+1]]==0)
            {
                flag=false;
                break;
            }
        }
        if (flag)
            ans++;
    } while (next_permutation(path,path+n));
    cout<<ans<<endl;
}