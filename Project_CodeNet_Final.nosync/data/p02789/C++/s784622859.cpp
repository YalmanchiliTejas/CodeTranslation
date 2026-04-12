#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const ll mod=1e9+7;
const ll inf = (ll)1e17;
const ld eps = 1e-12;
const ld PI = 3.14159265358979323846;
ll mul(ll a, ll b, ll m = mod) { return (ll)(a * b) % m;}
ll add(ll a, ll b, ll m = mod) { a += b; if(a >= m) a -= m; if(a < 0) a += m; return a;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==m)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
    }
