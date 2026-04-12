#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define se second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L


typedef long long ll;

const ll MOD =1e9+7;

bool graph[51][51];
bool vis[51];

int dfs(int vertex,int N,bool vis[51]){
    bool ok=true;
    for(int i=0;i<N;++i){
        if(vis[i]==false)
            ok=false;
    }
    if(ok)return 1;

    int ans=0;
    for(int i=0;i<N;++i){
        if(graph[vertex][i]==false)continue;
        if(!vis[i]){
            vis[i]=true;
            ans+=dfs(i,N,vis);
            vis[i]=false;
        }
    }
    return ans;
}

void solve(){
    int N,M;
    cin>>N>>M;

    for(int i=0;i<M;++i){
        int A,B;
        cin>>A>>B;
        graph[A-1][B-1]=graph[B-1][A-1]=true;
    }

    bool vis[51];
    for(int i=0;i<N;++i){
        vis[i]=false;
    }

    vis[0]=true;
    cout<<dfs(0,N,vis)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
