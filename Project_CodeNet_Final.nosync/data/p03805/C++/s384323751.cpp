#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int nextInt() {int a; cin >> a; return a;}
char nextChar() {char a; cin >> a; return a;}
double nextDouble() {double a; cin >> a; return a;}
string nextString() {string a; cin >> a; return a;}

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

signed main() {
    int N, M;
    cin >> N >> M;

	bool con[8][8];
	memset(con, false, sizeof(con));
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		con[a][b] = true;
		con[b][a] = true;
	}

	vector<int> v;
	rep(i, N) v.push_back(i);

	int ret = 0;
	do {
		bool ok = true;
		rep(i, N - 1) {
			ok &= con[v[i]][v[i + 1]];
		}
		ret += ok;
	} while (next_permutation(v.begin() + 1, v.end()));

	cout << ret << endl;

    return 0;
}
