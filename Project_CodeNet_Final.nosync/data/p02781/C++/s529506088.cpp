/**
 * @author: pr4shan7 (प्रशांत)
 */
// #define _DEBUG

#ifndef _DEBUG
#define NDEBUG
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// #define int long long
// #define double long double

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_set;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define endl '\n'
#define x first
#define y second
#define cai static_cast<int>
#define cal static_cast<long long>
#define cad static_cast<long double>
#define deb(z) cout << "// " << #z << " = " << z << endl;
const int N = 1e5 + 5;
const int INF = 1e9;
const int MV = 1e9 + 7;

inline int solve(string& n, int& k) {
  ll ans{};
  ll l = n.length();
  if (k == 3) {
    ans += ((9 * 9 * 3 * max(l - 1, 0LL) * max(l - 2, 0LL) * max(l - 3, 0LL)) >> 1) + ((max(n[0] - '0' - 1, 0) * max(l - 1, 0LL) * max(l - 2, 0LL) * 9 * 9) >> 1);
    if (l == 1)
      n = "0";
    else {
      do {
	n = n.substr(1, l - 1);
	l--;
      } while (l != 1 && n[0] == '0');
    }
  k--;
}

#ifdef _DEBUG
// deb(n); deb(l);
#endif

if (k == 2) {
  ans += ((9 * 9 * max(l - 1, 0LL) * max(l - 2, 0LL)) >> 1) + (max(n[0] - '0' - 1, 0) * max(l - 1, 0LL) * 9);
  if (l == 1)
    n = "0";
  else {
    do {
      n = n.substr(1, l - 1);
      l--;

      #ifdef _DEBUG
      	// deb(n); deb(l); 
      #endif
      
    } while (l != 1 && n[0] == '0');
  }
  k--;
}

#ifdef _DEBUG
deb(n);
#endif

if (k == 1) {
  ans += max(n[0] - '0', 0) + 9 * max(l - 1, 0LL);
}

return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  string n;
  int k;
  cin >> n >> k;
  cout << solve(n, k) << endl;

  return 0;
}
