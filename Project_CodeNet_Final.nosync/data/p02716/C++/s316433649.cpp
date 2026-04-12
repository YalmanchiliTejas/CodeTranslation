#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define sz(i) (int)(i.size())
#define F first
#define S second
#define L long double
#define P pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = (int)1e9 + 7;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = 2*(int)1e5 + 10;

int n, a[N], dp[N][5];
int till = 0;

bool bad = false;

int solve(int idx, int removed){
   if (removed < 0){
      return -inf;
   }
   if (idx >= n){
      if (bad and n%2 and removed == 2){
         return -inf;
      }
      return 0;
   }
   int &ans = dp[idx][removed];
   if (ans != -1){
      return ans;
   }
   ans = -inf;
   smax(ans, solve(idx+1, removed-1));
   smax(ans, a[idx] + solve(idx+2, removed));
   return ans;
}

int32_t main(){_
   
   cin>>n;

   for (int i = 0; i < n; ++i)
   {
      cin>>a[i];
   }
      
   int ans = -inf;
   memset(dp, -1, sizeof dp);

   if (n%2){
      bad = true;
      smax(ans, solve(0, 2));
      bad = false;
      memset(dp, -1, sizeof dp);
      smax(ans, solve(1, 1));
   }
   else{
      smax(ans, solve(0, 1));
      memset(dp, -1, sizeof dp);
      smax(ans, solve(1, 0));
   }
   
   cout<<ans;  

   return 0;
}