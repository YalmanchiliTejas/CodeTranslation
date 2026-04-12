#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i = m; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define MOD 1000000007
typedef long long LL;
template<class T> inline void chmax(T & a, T b) { if (a < b) { a = b; } }
template<class T> inline void chmin(T& a, T b) { if (a > b) { a = b; } }
template<class T> void print_vector(vector<T> vec) {
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "]" << endl;
}
template<class T> void print_pair_vector(vector<pair<T, T> > vec) {
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++) {
		cout << "(" << vec[i].first << "," << vec[i].second << ") ";
	}
	cout << "]" << endl;
}

int main(void) {
	int H, W;
	cin >> H >> W;

	vector<string> grid(H);
	rep(i, H) cin >> grid[i];

	vector<int> column_mark(W);
	vector<int> row_mark(H);

	rep(i, H) {
		if (grid[i].find("#") != string::npos) {
			row_mark[i] = 1;
		}
	}

	rep(i, W) {
		rep(j, H) {
			if (grid[j][i] == '#') {
				column_mark[i] = 1;
				break;
			}
		}
	}

	rep(i, H) {
		rep(j, W) {
			if (row_mark[i] and column_mark[j]) {
				cout << grid[i][j];
			}
		}
		if (row_mark[i]) {
			cout << endl;
		}
	}
}
