#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define mod         1000000007
#define FAST        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n)      for(int i=0;i<n;i++)
#define fp(i,k,n)   for(int i=k;i<=n;i++)
#define fr(i,k,n)   for(int i=k;i>=n;i--)
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define dbg(x)      cout << (#x) << " is " << (x) << '\n' 
#define F           first
#define S           second
#define sz(x)       (int)(x).size()
#define lb          lower_bound
#define ub          upper_bound
#define mems(x)     memset(x,0,sizeof(x))
#define all(a)      a.begin(),a.end()
 
/*---------------------------------------------------------------------------------------------------*/
void solve()
{
    int n;
    cin >> n;

    int a[n], sum[n];

    cin >> a[0];
    sum[0] = a[0];

    fp (i, 1, n - 1) 
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
        // sum[i] %= mod;

    }

    int ans = 0;

    f (i, n)
    {
        int curr = sum[n - 1] - sum[i];
        curr %= mod;

        curr *= a[i];
        curr %= mod;
        ans += curr;
    }

    cout << ans % mod;
} 
 
signed main()
{
  FAST
  int T=1;
//   cin >> T;
  while(T--) solve();
  return 0;
}