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
vl a(51),p(51);
ll solve(ll N,ll K,vl a=a,vl p=p){
    if(N==0)return 1;
    if(K==1)return 0;
    if(K<=a[N-1]+1)return solve(N-1,K-1);
    if(K==a[N-1]+2)return p[N-1]+1;
    if(K<=2*a[N-1]+2)return p[N-1]+1+solve(N-1,K-a[N-1]-2);
    return 2*p[N-1]+1;
}
int main(){
    a[0]=1,p[0]=1;
    rep(i,50)a[i+1]=2*a[i]+3;
    rep(i,50)p[i+1]=2*p[i]+1;
    ll N,K;cin>>N>>K;
    cout<<solve(N,K)<<endl;
    return 0;
}