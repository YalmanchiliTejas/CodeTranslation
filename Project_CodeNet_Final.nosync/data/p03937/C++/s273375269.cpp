#include <bits/stdc++.h>
#define P pair<int,int>
#define All(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
typedef long long ll;
using namespace std;
const int INF = 1e9, MOD = 1e9 + 7;
const ll LINF = 1e18;
int main() {
	int h, w, cnt = 0;
	cin >> h >> w;
	for (int i = 0; i < h * w; i++) {
		char c;
		cin >> c;
		if (c == '#') {
			cnt++;
		}
	}
	if (cnt == h + w - 1) {
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}
	return 0;
}