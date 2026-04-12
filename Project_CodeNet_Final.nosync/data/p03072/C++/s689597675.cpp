#include <bits/stdc++.h>

using namespace std;
#define int int64_t
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define gsort(x) sort((x).begin(), (x).end(), greater<int>())
#define rv(s) reverse((s).begin(), (s).end())
#define pii pair<int, int>
#define re(s) reverse((s).begin(), (s).end())
#define setout(n, x) setw(n) << setfill(x)
#define Fixed fixed << setprecision(10);
const long long mod = 1e9 + 7;

signed main()
{
   cin.tie(0);
   ios::sync_with_stdio(false);

   int n, cnt = 0, big;
   cin >> n;
   vector<int> x(n);

   rep(i, n)
   {
      cin >> x[i];
      if (i == 0)
         ++cnt, big = x[i];
      else if (x[i] >= big)
         ++cnt, big = x[i];
   }
   cout << cnt << '\n';
}