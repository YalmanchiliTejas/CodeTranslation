#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;
#define endl '\n'
#define pb push_back
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1e9 + 7)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define REP(i,n) for(int i = 0;i < (n);i++)
#define FOR(i,a,b) for(int i = (a);i <= (b);i++)
#define YES(n) cout << ((n) ? "YES" : "NO" ) << endl
#define Yes(n) cout << ((n) > "Yes" : "No" ) << endl


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

template <class T = int> T in() { T x; cin >> x; return (x); }
template <class T = int> void out(T x) { cout << (x) << endl; }

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

void solve() {

	int h, w, j;
	cin >> h >> w;

	vector<vector<char>> box;
	box.resize(h);
	REP(i, h) {
		box[i].resize(w);
	}

	REP(i, h) {
		REP(j, w) {
			cin >> box[i][j];
		}
	}

	REP(i, h) {
		for (j = 0; j < w; j++) {
			if (box[i][j] != '.') {
				break;
			}
		}
		if (j == w) {
			box.erase(box.begin() + i);
			i--; h--;
		}
	}

	REP(i, w) {
		for (j = 0; j < h; j++) {
			if (box[j][i] != '.') break;
		}
		if (j == h) {
			REP(k, h) {
				box[k].erase(box[k].begin() + i);
			}
			i--; w--;
		}
	}

	REP(i, h) {
		REP(j, w) {
			cout << box[i][j];
		}
		cout << endl;
	}

	return;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	solve();

	return 0;

}