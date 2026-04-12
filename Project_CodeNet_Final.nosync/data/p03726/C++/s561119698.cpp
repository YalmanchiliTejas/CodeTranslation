#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)
#define mod2 998244353

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N;
vector<int>G[100005];
int depth[100005],parent[100005];
bool used[100005];
void dfs(int x,int par){
    for(int i:G[x])if(i!=par){
        depth[i]=depth[x]+1;
        parent[i]=x;
        dfs(i,x);
    }
}
signed main(){
    cin>>N;
    rep(i,N-1){
        int a,b;cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,0);
    vector<P>v;
    rep(i,N)v.push_back(P(depth[i],i));
    sort(all(v),greater<>());
    for(P i:v){
        if(!used[i.second]){
            if(!i.second||used[parent[i.second]]){
                cout<<"First"<<endl;
                return 0;
            }
            used[parent[i.second]]=true;
        }
    }
    cout<<"Second"<<endl;
}