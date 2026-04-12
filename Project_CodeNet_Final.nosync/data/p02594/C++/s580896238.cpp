#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define fo(i,a) for(ll i=0;i<a;i++)
#define Fo(i,a,n) for(ll i=a; i<n; i++)
#define u_m unordered_map
#define u_s unordered_set
#define ff first
#define ss second
#define mp make_pair
using namespace std;
ll __pow(ll x, ll y) {ll res = 1;while(y>0){if(y&1) res*=x; y>>=1; x*=x;}return res;}
ll gcd(ll a , ll b){if(b==0) return a;a%=b;return gcd(b,a);}
bool isprime(ll n){for(ll i=2; i*i<=n; i++){if(n%i==0) return 0;}return 1;}
ll n,m,x,y,z,k;
ll dp(ll n){
    if(n<10) return max((ll)1, n);
    else return max((n%10)*dp(n/10), 9*dp(n/10-1));
}
void solve(){
    cin>>n;
    if(n>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
    ll t=1;
    //cin >> t;
    for(ll i=1; i<=t; i++){
        solve();
    }
    return 0;
}
