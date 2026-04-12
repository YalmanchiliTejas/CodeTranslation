#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2e5 + 7;
multiset<int> st;
int n, m, a[maxn];
pair<int, int> p[maxn];

int mx[maxn], mn[maxn], Min = 1e9, Max;
bool d2[maxn];
int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
   cin >> n;
   for(int i = 1; i <= n; i++)
   {
      int x, y;
      cin >> x >> y;
      if(x > y) swap(x, y);
      p[i] = {x, y};
      Min = min({Min, x, y});
      Max = max({Max, x, y});
      st.insert(x);
   }
   int Min1 = 1e9, Max1 = 0, ans;
   for(int i = 1; i <= n; i++)
   {
      Max1 = max(Max1, p[i].first);
      Min1 = min(Min1, p[i].second);
   }
   ans = (Max1 - Min) * (Max - Min1);
   sort(p + 1, p + n + 1);
   ans = min(ans, (*st.rbegin() - *st.begin()) * (Max - Min));
   for(int i = 1; i <= n; i++)
   {
      st.erase(st.find(p[i].first));
      st.insert(p[i].second);
      ans = min(ans, (*st.rbegin() - *st.begin()) * (Max - Min));
   }
   cout << ans;
}