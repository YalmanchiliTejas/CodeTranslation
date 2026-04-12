#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int>graph[MAX];
int ans,n,m;
void dfs(int src,int used[],int tot)
{
    for(int i=0;i<graph[src].size();i++){
        int child=graph[src][i];
        if(used[child]==0){
            used[child]=1;
            dfs(child,used,tot+1);
            used[child]=0;
        }
    }
    if(tot==n)
        ans++;

}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int used[20]={0};
    used[1]=1;
    dfs(1,used,1);
    cout<<ans<<endl;
    return 0;
}
