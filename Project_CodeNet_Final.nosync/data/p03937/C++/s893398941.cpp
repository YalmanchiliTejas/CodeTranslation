#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class question {
public:
	int H, W;
	vector<vector<int>> A;
	int di[2] = { 1,0 };
	int dj[2] = { 0,1 };
	void dfs() {
		stack<P> st;
		st.push(P(0, 0));
		A[0][0] = 1;
		P prev;
		while (!st.empty()) {
			int i = st.top().first, j = st.top().second;
			if (i == H - 1 && j == W - 1) {
				A[H - 1][W - 1] = 1;
				return;
			}
			REP(k, 3) {
				if (k < 2) {
					int i0 = i + di[k], j0 = j + dj[k];
					if (i0 < H && j0 < W && !A[i0][j0]) {
						A[i0][j0] = 1;
						prev = P(i, j);
						st.push(P(i0, j0));
						break;
					}
				}
				else {
					A[i][j] = -1;
					return;
				}
			}
		}
	}
	void ans() {
		cin >> H >> W;
		A.resize(H, vector<int>(W));
		REP(i, H)REP(j, W) {
			char c;
			cin >> c;
			if (c == '.') A[i][j] = 1;
			else A[i][j] = 0;
		}
		dfs();
		string res = "Possible\n";
		REP(i, H)REP(j, W) {
			if (A[i][j] <= 0) res = "Impossible\n";
		}
		cout << res;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	question q;
	q.ans();
	
	return 0;
}

