#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < ll > vl;
typedef vector < vl > vvl;
typedef pair < ll, ll > pll;
typedef vector < pair < ll, ll > > vpll;
#define kill freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define fo(i,n) for(ll i=0;i<n;i++)
#define rev(i,n) for(ll i=n-1;i>=0;i--)
#define all(c) c.begin(), c.end()
#define go(c,it) for(auto it=(c).begin(); it!=(c).end(); it++)
#define fi first
#define se second
#define MOD 998244353
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD1 1000000007
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
#define oo 100000000000000000
const ll dx[]={-1,0,1, 0,-1,1, 1,-1};
const ll dy[]={ 0,1,0,-1, 1,1,-1,-1};
void solve(){
    ll x;
    cin>>x;
    if(x>=30)cout<<"Yes\n";
    else cout<<"No\n";
}

int main(){
    Boost();
    ll T = 1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
