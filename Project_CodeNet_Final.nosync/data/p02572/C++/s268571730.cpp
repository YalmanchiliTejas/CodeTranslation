# include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define fi first
# define se second
# define mp make_pair
# define gcd(m,n)  __gcd(m, n)
# define pr_double(x) cout << fixed << setprecision(10) << x
using namespace std;



const ll m = 1e9+7;
ll a[200007];
ll pre[200007];
int main() {
  ll n; cin>>n;
  for(ll i=1;i<=n;i++)
  {
      cin>>a[i];
      pre[i] = (pre[i-1]%m + a[i]%m)%m;
  }
  ll ans=0;
  for(ll i=1;i<=n;i++)
  {
      ll t = (pre[n]%m - pre[i]%m + m)%m;
      t = (t%m * a[i]%m)%m;
      ans = (ans%m + t%m)%m;
  }
  cout<<ans<<endl;

}
