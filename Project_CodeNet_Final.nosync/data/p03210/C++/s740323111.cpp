#include <bits/stdc++.h>

using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef LOCAL_DEFINE
	freopen("input.txt", "r", stdin);
#endif

	int x;
	cin >> x;
	if (x == 3 or x == 5 or x == 7) {
		cout << "YES" << '\n';
	} else cout << "NO" << '\n';

#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

  return 0;
}