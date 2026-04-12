#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define fr(i,j,k) for(i = j; i < (k); i++)
#define all(x) x.begin(), x.end()
#define el '\n'
#define remax(a,b) a = max(a, b)
#define remin(a,b) a = min(a, b)
#define sz(x) int32_t(x.size())

typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
// --------------------------------------------------------------------

const pii dxy[] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
const int mod = 1e9 + 7;
const int INF = 2e18;
const ld EPS = 1e-9;
const int NN = 1e5 + 2;



void solve() {
      int i = 0, j = 0, k = 0, n = 0, m = 0; 
      cin >> n;
      vi a(n);

      fr(i, 0, n) {
            cin >> a[i];
      }

      vi assign;
      fr(i, 0, n) {
            int searchTerm = a[i], idx = -1;
            {
                  int lo = 0, hi = sz(assign) - 1, mid;
                  while(lo <= hi) {
                        mid = lo+hi >> 1;
                        if(assign[mid] < searchTerm) {
                              idx = mid;
                              hi = mid - 1;
                        } else {
                              lo = mid + 1;
                        }
                  }
            }

            if(idx == -1) {
                  assign.pb(searchTerm);
            } else {
                  assign[idx] = searchTerm;
            }
      }     

      cout << sz(assign) << endl;
}

int32_t main() {
      ios::sync_with_stdio(false); cin.tie(0); 
      int T = 1; 
      // cin >> T;
      for(int tc = 1; tc <= T; tc++) {
            solve();
       }
      return 0;
}