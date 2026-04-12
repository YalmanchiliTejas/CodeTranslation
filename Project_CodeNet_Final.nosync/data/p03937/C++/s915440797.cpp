#include <bits/stdc++.h>

using namespace std;
#define int int64_t
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define reps(i, a, n) for (int i = (a); i < (n); --i)
#define all(x) (x).begin(), (x).end()
#define gsort(x, n) sort((x), (x + n) greater<int>())
#define rv(s) reverse((s).begin(), (s).end())
#define setout(n, x) setw(n) << setfill(x)
#define Fixed(n) fixed << setprecision(n)
#define pb(x, a) (x).push_back(a)
#define fb(x, a) (x).flont_back(a)
#define eb(x, a) (x).emplaes_back(a)
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1e9 + 7;

signed main()
{
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);

   int h, w, cnt = 0;
   string s[10];
   cin >> h >> w;

   rep(i, 0, h)
   {
      cin >> s[i];
      rep(j, 0, w)
      {
         if (s[i][j] == '#')
            ++cnt;
      }
   }

   if (cnt == (h + w - 1))
      cout << "Possible" << '\n';
   else
      cout << "Impossible" << '\n';
}