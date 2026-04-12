#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

int N,M,ans;
int G[10][10];
bool used[10];

void dfs(int v,int c){
    if(c==N){
        ans++;
        return;
    }
    used[v]=1;
    REP(i,N) if(!used[i] and G[v][i]) dfs(i,c+1);
    used[v]=0;
}

signed main()
{
    cin>>N>>M;
    REP(i,M){
        int a,b; cin>>a>>b;
        a--; b--;
        G[a][b]=G[b][a]=1;
    }
    dfs(0,1);
    cout<<ans<<endl;
}
