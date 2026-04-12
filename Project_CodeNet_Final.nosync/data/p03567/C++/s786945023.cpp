#include <bits/stdc++.h>

using namespace std;
long long x[10000010], y[10000010];
#define rep(i, n) for (int i = 0; i < (n); i++)
#define lep(j, n) for (int j = 0; j < (n); j++)
#define reps(i, n) for (int i = 1; i < (n); i++)
#define leps(i, n) for (int j = 1; j < (n); j++)
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define int long long
#define gsort(x, n) sort((x), (x) + (n), greater<int>());
#define setout(n, x) setw(n) << setfill(x)
#define Fixed fixed << setprecision(10);
const long long mod = 1e9 + 7;

signed main()
{

   cin.tie(0);
   ios::sync_with_stdio(false);

   string s;
   cin >> s;
   string a = "AC";

   if (s.find(a) != string::npos)
      cout << "Yes" << '\n';
   else
      cout << "No" << '\n';
}