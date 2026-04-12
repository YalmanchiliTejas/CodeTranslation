#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 200010;

int n, m;
int p[N], cnt[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
long long sum[N];
int a[N];
signed main()
{
   //a0*a1 + a0*a2 * a0 *a3 + a1*a2 + a2*a3
    cin >> n;
  for(int i = 1; i <= n; i++)
  {
  	int t;
    cin >> t;
    a[i] = t;
    
  }

  for(int i = 1; i <=n;i++)
  {
  	sum[i] = a[i] + sum[i-1];
  }
  int ans = 0;
  for(int i = 1; i <= n; i++)
  {
  	ans = (ans +a[i]*((sum[n]-sum[i])%mod))%mod % mod;
  }
  
  cout << ans << endl;
     
    return 0;
}
