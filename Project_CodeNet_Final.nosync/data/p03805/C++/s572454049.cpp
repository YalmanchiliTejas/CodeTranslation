#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main(){
    int N,M;cin>>N>>M;
    vector<set<int>> G(N);
    rep(i,M){
        int a,b;cin>>a>>b;
        a--,b--;
        G[a].insert(b),G[b].insert(a);
    }
    vl v;
    rep(i,N)v.push_back(i);
    int ans=0;
    do{
        if(v[0]!=0)break;
        int now=0;
        rep(i,N-1)if(G[v[i]].count(v[i+1]))now++;
        if(now==N-1)ans++;
    }while(next_permutation(all(v)));
    cout<<ans<<endl;
    return 0;
}