#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[200005][3];
int main(){
int  n;
cin>>n;
V<ll> a(n);
for(int i=0;i<200005;i++)for(int j=0;j<3;j++)dp[i][j]=-inf;
dp[0][0]=0;
int skip=1+(n%2);
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++){
    for(int j=0;j<=skip;j++){
        if(j!=skip){
            chmax(dp[i+1][j+1],dp[i][j]);
        }
        chmax(dp[min(n,i+2)][j],dp[i][j]+a[i]);
    }
}
cout<<max(dp[n][skip],dp[n][skip-1])<<"\n";
}