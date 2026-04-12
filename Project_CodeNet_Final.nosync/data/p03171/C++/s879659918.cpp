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
const int N = 3e3 + 10;
const int M = 1e6+10;
/*=================================================================================*/

int n, a[N];
ll dp[N][N];

int main() {
   cin>>n;
   for1(i, n) scanf("%d", &a[i]);
   for(int i = n; i; --i)
      for(int j = i; j <= n; ++j) {
         dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
      }
   cout<<dp[1][n]<<endl;
}