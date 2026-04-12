#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	int count = 0;
	rep(i, h) {
		rep(j, w) {
			char c;
			cin >> c;
			if (c == '#') count++;
		}
	}
	if (count == h + w - 1) {
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}
	return 0;
}

