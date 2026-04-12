#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;
using vi = vector <int>;
#define op operator
#define pb push_back

int a[511];

int main() {
	cout << fixed << setprecision(9);
	ios :: sync_with_stdio(0);

	int x, y; char c;
	map <int, int, greater <int>> mp;
	while(cin >> x >> c >> y) {
		if(!x && !y) break;
		a[x] = y;
		mp[y] = 0;
	}
	int cnt = 0;
	for(auto &p : mp)
		p.second = ++ cnt;
	for(int q; cin >> q; )
		cout << mp[a[q]] << '\n';

	return 0;
}