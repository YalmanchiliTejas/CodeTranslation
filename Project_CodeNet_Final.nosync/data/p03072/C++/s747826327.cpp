#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
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
const int N = 5*(int)1e5 + 10;

int n, h[N];
int32_t main(){_

   cin>>n;

   for (int i = 0; i < n; ++i)
   {
      cin>>h[i];
   }

   int ans = 0;
   for (int i = 0; i < n; ++i)
   {
      bool yes = true;
      for (int j = i-1; j >= 0; --j)
      {
         yes &= (h[i] >= h[j]);
      }
      if(yes)ans++;
   }

   cout<<ans;

   return 0;
}

// Common sense: do smth instead of nothing