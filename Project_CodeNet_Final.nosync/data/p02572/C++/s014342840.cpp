#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vll vector<ll>
#define vvll vector<vll>
#define mll map<ll,ll>
#define f(i,m,n) for(i=m;i<n;i++)
#define ee endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define take(v,n) for(i=0;i<n;i++) cin>>v[i];
#define NO() cout<<"IMPOSSIBLE"<<endl
#define YES() cout<<"Yes"<<endl
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sot(v) sort(v.begin(),v.end());
ll mod =1000000007;  
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}

ll powe(ll x, ll y){
    ll res = 1;
    while (y > 0){
        if (y & 1) res = (res*x)%mod;
        y = y>>1;
        x = (x*x)%mod;
    }
    return res;
}

void solve()
{
    ll i,j,n,k,m,w,q;
    cin>>n;
    vll v(n);
    take(v,n);
    ll ans=0;
    ll sum=0;
    for(i=0;i<n;i++)
    {
        ans=(ans+((sum)*v[i])%mod)%mod;
        sum=(sum+v[i])%mod;
    }
    cout<<ans<<ee;
}
int main() {
    fast;
    ll i,j,l,k,t,n;
    t=1;
    for(i=1;i<=t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}