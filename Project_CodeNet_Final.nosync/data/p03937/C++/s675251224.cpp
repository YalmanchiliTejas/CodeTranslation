#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	ll ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c;
			cin >> c;
			if (c == '#')ans++;
		}
	}
	if (ans == h + w - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;

}