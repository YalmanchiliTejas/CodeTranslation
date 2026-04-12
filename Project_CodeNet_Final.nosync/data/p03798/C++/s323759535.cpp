#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<functional>
#include<iomanip>
#include<queue>
#include<cassert>
#include<tuple>
#include<set>
#include<map>
#include<list>
#include<bitset>
#include<utility>
#include<numeric>

#define PB push_back
#define all(a)  (a).begin(),(a).end()
#define ALL(v) begin(v), end(v)
#define DWN(a)  (a).begin(),(a).end(), greater<int>()
#define rep(i, m) for (int i = 0; i < m; i++)
#define REP(i, n, m) for (int i = n; i < m; i++)
#define V vector<int>
#define VV vector<V>
#define VVV vector<VV>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int inf = (int)1e9;
const ll INF = (ll)1e18;
const ll MOD{ (ll)1e9 + 7 };
const long double EPS = 1e-10;

int main() {
	int n;
	cin >> n;
	string s, res = "";
	cin >> s;

	rep(i, 2) {
		rep(j, 2) {
			res = "";
			
			if (i == 0) res += "S";
			else res += "W";

			if (j == 0) res += "S";
			else res += "W";

			for (int k = 1; k < n - 1; k++) {
				if (res[k] == 'S') {
					if (s[k] == 'o') {
						res.push_back(res[k - 1]);
					}
					else {
						res.push_back(res[k - 1] == 'S' ? 'W' : 'S');
					}
				}
				else {
					if (s[k] == 'x') {
						res.push_back(res[k - 1]);
					}
					else {
						res.push_back(res[k - 1] == 'S' ? 'W' : 'S');
					}
				}
			}

			bool f = true;
			rep(i, n) {
				if (s[i] == 'o') {
					if (res[i] == 'S') {
						if (res[(n + i - 1) % n] != res[(n + i + 1) % n]) { //前と後
							f = false;
						}
					}
					else {
						if (res[(n + i - 1) % n] == res[(n + i + 1) % n]) {
							f = false;
						}
					}
				}
				else {
					if (res[i] == 'S') {
						if (res[(n + i - 1) % n] == res[(n + i + 1) % n]) {
							f = false;
						}
					}
					else {
						if (res[(n + i - 1) % n] != res[(n + i + 1) % n]) {
							f = false;
						}
					}
				}
			}

			if (f) {
				cout << res << endl;
				return 0;
			}
		}
	}
	
	cout << -1 << endl;
	return 0;
}