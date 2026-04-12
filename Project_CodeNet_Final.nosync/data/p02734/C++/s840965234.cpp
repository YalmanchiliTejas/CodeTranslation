#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define sz(i) (int)(i.size())
#define F first
#define S second
#define L long double
#define P pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = 998244353;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = 3e3 + 100;

int n, a[N], s;
int dp[N][N];

int solve(int idx, int s){
   if(s == 0)
      return n - (idx) + 1;
   if(s < 0)
      return 0;
   if(idx >= n)
      return 0;
   int &ans = dp[idx][s];
   if(ans != -1)
      return ans;
   ans = solve(idx+1, s) + solve(idx+1, s - a[idx]);
   ans %= mod;
   return ans;
}

void solve(){
   cin>>n>>s;

   for (int i = 0; i < n; ++i)
   {
      cin>>a[i];
   }

   memset(dp, -1, sizeof dp);

   int ans = 0;
   for (int i = 0; i < n; ++i)
   {
      ans += solve(i, s);
      ans %= mod;
   }

   cout<<ans;
}

int32_t main(){_
   
   int t = 1;
   //cin >> t;

   while(t--){
     solve();
     cout << endl;
   }
   

   return 0;
}