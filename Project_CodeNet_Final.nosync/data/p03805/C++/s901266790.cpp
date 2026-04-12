#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using llong = long long;
using P = pair<int, int>;
const int inf = 1 << 20;
const int mod = 1e9 + 7;

int g[8][8];
int main() {
   int n, m;
   cin >> n >> m;
   rep(i, m) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      g[a][b] = 1;
      g[b][a] = 1;
   }
   vector<int> p(n);
   rep(i, n) { p[i] = i; }
   int ans = 0;
   do {
      if (p[0] != 0)
         continue;
      int isok = true;
      rep(i, n - 1) {
         if (g[p[i]][p[i + 1]] == 0)
            isok = false;
      }
      if (isok)
         ans++;
   } while (next_permutation(p.begin(), p.end()));
   cout << ans << endl;
   return 0;
}