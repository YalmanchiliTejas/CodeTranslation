#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rf(i,a,b) for(ll i=a;i>=b;i--)
#define sf(i,s) for(ll i=0;s[i]!='\0';i++)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define inf 1e18
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define tr(v,i) for(typeof(v).begin() i = v.begin(); i != v.end(); i++)
#define pre(v,x) (v.find(x) != v.end())
#define vpre(v,x) (find(all(v),x) != v.end())
#define gcd(x,y) __gcd(x,y)
#define bc(x) __builtin_popcountll(x)
//cin.ignore(1, '\n');
ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % mod;
    else
    {
        ll t = power(a, b / 2);
        if (b % 2 == 0)
            return ((t % mod) * (t % mod)) % mod;
        else
            return ((((t % mod) * (t % mod)) % mod) * ((a % mod) % mod)) % mod;
    }
}
void solve()
{
  ll n,i,ans=0,s=0;
  cin>>n;
  ll a[n+1];
  f(i,0,n)
  {
      cin>>a[i];
      s=(s+a[i]);
  }
  f(i,0,n)
  {
      s-=a[i];
      ans+=((a[i]%mod)*(s%mod))%mod;
      ans=ans%mod;
  }
  cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
  //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
