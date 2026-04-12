#include <bits/stdc++.h>
#define eps 1e-3
#define pi acos(-1.0)
#define inf 0x3f
#define INF 0x3f3f3f3f
#define pb push_back
#define debug1 cout<<"&&";
#define debug2 cout<<"**";
#define ms(a, x) memset(a, x, sizeof(a))
#define for0(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 110;
/*=================================================================================*/

ll dp[N][M][2];
string str;
int a[N], d, len;

int dfs(int k, int now, int lim) {
   if(dp[k][now][lim] >= 0) return dp[k][now][lim];
   if(k == len) return dp[k][now][lim] = (now == 0);
   ll sum = 0;
   int up = lim ? a[k] : 9;
   for0(i, up+1) {
      sum += dfs(k+1, (now+i) % d, lim && i==up);
      sum %= mod;
   }
   return dp[k][now][lim] = sum;
}

int main() {
   ms(dp, -1);
   cin>>str>>d;
   len = str.size();
   for0(i, len) a[i] = str[i] - '0';
   ll ans = (dfs(0, 0, 1) - 1 + mod) % mod;
   cout<<ans<<endl;
   return 0;
}