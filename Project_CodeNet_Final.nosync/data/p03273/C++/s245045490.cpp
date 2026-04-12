#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<deque>
#include<bitset>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(ll i = a; i < b; i++)

int main() {

	int h, w;
	cin >> h >> w;

	vector<vector<char>> a(h, vector<char>(w));
	rep(i, 0, h) {
		rep(j, 0, w) cin >> a[i][j];
	}

	vector<int> s(100, 0), v(100, 0);

	rep(i, 0, h) {
		int j = 0;
		while (a[i][j] == '.') {
			if (j == w - 1) {
				s[i] = 1;
				break;
			}
			j++;
		}
	}

	rep(i, 0, w) {
		int j = 0;
		if (w != 1) {
			while (a[j][i] == '.') {
				if (j == h - 1) {
					v[i] = 1;
					break;
				}
				j++;
			}
		}
	}

	rep(i, 0, h) {
		if (s[i] != 1) {
			rep(j, 0, w) {
				if (v[j] != 1) cout << a[i][j];
			}
			cout << endl;
		}
	}
}