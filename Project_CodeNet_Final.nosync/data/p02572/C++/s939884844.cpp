#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define scan(any)       for(auto &i:any) cin>>i;
#define print(any)      for(auto i:any) cout<<i<<" "; 
#define endl            '\n'
#define pb push_back
#define vll vector<ll> 
#define f(i,x,y)  for(i=x;i<y;i++)
#define INF     LLONG_MAX
#define fast    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define s(x) sort(x.begin(),x.end())
#define all(v) v.begin(),v.end()
#define p2(n,x)    cout << fixed << setprecision(x) <<n<<endl; 
#define pll    pair<ll,ll> 
#define ff first
#define ss second
#define blt(x)   __builtin_popcount(x)

void solve()
{
    ll mod=1e9+7;
    ll i,j,k,n;
    cin>>n;
    vll v(n);
    scan(v);
    ll sum=0;
    f(i,0,n)
    sum=(sum+v[i])%mod;

    ll ans=0;

    f(i,0,n)
    {
        sum=(sum-v[i]+mod)%mod;
        ans=(ans+((sum*v[i])%mod))%mod;
    }
    cout<<ans;

}

int main()
{
   
    fast
    ll t = 1;

    

    while(t--)
    solve();
    
    return 0;
}