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
	int h, w;
	cin >> h >> w;
	char a[10][10];

	int sum = 0;
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
			if (a[i][j] == '#') sum++;
		}
	}
	cout << (sum == h + w - 1 ? "P" : "Imp") << "ossible" << endl;
	return 0;
}