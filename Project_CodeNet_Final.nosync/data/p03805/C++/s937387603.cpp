#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

//O(n^2 * 2^n)
ll hamilton(vector<vector<bool>> g){
    int n=g.size();
    ll dp[n][(1<<n)]={};

    //本当なら全点始点なのでこっち
    // rep(i,n) dp[i][(1<<i)]=1;
    // One-stroke Path は始点が1なのでこっち
    dp[0][1]=1;
    for(int bit=1;bit<(1<<n);bit++){
        for(int u=0;u<n;u++)if((bit>>u)&1){
            for(int v=0;v<n;v++){
                if(!((bit>>v)&1) and g[u][v]) dp[v][bit|(1<<v)]+=dp[u][bit];
            }
        }
    }
    ll ret=0;
    rep(i,n) ret+=dp[i][(1<<n)-1];
    return ret;
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n,m;cin>>n>>m;
    vector<vector<bool>> g(n,vector<bool>(n,false));
    rep(i,m){
        int a,b;cin>>a>>b;a--,b--;
        g[a][b]=true;g[b][a]=true;
    }
    cout<<hamilton(g)<<endl;
    return 0;
}
