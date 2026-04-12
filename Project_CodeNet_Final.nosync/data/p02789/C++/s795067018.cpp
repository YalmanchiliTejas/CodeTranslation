#include<bits/stdc++.h>

#define int long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define TASK ""

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

signed main() {
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
if (strlen(TASK) > 0)
	freopen(TASK".in", "r", stdin),
	freopen(TASK".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  cout << (n == m ? "Yes\n" : "No\n");

	return 0;
}
