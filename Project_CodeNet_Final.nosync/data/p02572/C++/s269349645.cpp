#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)     for(int i=a;i<(b);i++)
#define lop(n)         for(int i=0;i<n;i++)
#define revlop(n)      for(int i=n-1;i>=0;i--)
#define trav(a,x)      for(auto &a :x)
#define all(x)         begin(x),end(x)
#define mod            1000000007
#define inf            1e18
#define ps(x,y)        fixed<<setprecision(y)<<x
#define w(x)           int x; cin>>x;

#define pb             push_back
#define mp             make_pair
#define lb             lower_bound
#define ub             upper_bound
#define bs             binary_search
#define F              first
#define S              second

typedef long long                ll;
typedef vector<int>              vi;
typedef pair<int, int>           pii;
typedef vector<pair<int, int>>   vpii;
typedef vector<pair<ll, ll>>     vpll;
ll a[200005];
ll pre[200005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ll n;
  cin >> n;

  rep(i, 0, n)
  {
    cin >> a[i];
  }
  sort(all(a), greater<int>());
  rep(i, 0, n)
  {
    if (!i)
      pre[i] = a[i];
    else
      pre[i] = (a[i] + pre[i - 1]) % mod;
  }
  ll ans = 0;
  rep(i, 1, n)
  {
    ans = (ans % mod + (pre[i - 1] * a[i]) % mod) % mod;
  }
  cout << ans;
  return 0;
}
