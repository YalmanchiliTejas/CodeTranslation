#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int MAX_N=8;
int N,M;
vector<int>G[MAX_N];
bool visited[MAX_N];

int dfs(int o,int k,bool visited[MAX_N]){
    bool fin=true;
    REP(i,N)if(!visited[i])fin=false;
    if(fin)return 1;
  	int ret=0;
    for(auto v:G[k]){
        if(!visited[v]&&o!=v){
            visited[v]=true;
            ret+=dfs(k,v,visited);
            visited[v]=false;
        }
    }
    return ret;
}

signed main(){
    cin>>N>>M;
    REP(i,M){
        int a,b;cin>>a>>b;a--;b--;
        G[a].eb(b);
        G[b].eb(a);
    }
    bool visited[N];
    REP(i,N)visited[i]=false;
  	visited[0]=true;
    cout<<dfs(-1,0,visited)<<endl;
}