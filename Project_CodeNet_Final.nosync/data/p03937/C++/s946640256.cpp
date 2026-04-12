#include<bits/stdc++.h>

using namespace std;


#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back

const int N = 1e6 + 1, MOD = 1e9 + 7, mod = 998244353, INF = 3e18;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int pref[N];
char c[200][200];

signed main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j  = 0; j < m; j++) {
         cin >> c[i][j];
         if (c[i][j] == '#') pref[i]++;
      }
   }
   int j = 0;
   for (int i = 0; i < n; i++) {
      int kol = 0;
      while (j < m && c[i][j] == '#') kol++, j++;
      if (kol != pref[i] || pref[i] == 0) {
         cout << "Impossible";
         return 0; 
      }
      j--;
   }
   if (j == m - 1) {
      cout << "Possible";
   }
   else cout << "Impossible";

}