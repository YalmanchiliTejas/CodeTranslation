#include<iostream>
#include <climits>
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
#include<deque>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define INF (int)1e9
#define INFL (ll)1e11
using namespace std;
typedef long long ll;
typedef pair<int, int> P;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H, vector<char>(W)), b;
	REP(i, H)REP(j, W) cin >> a[i][j];
	vector<bool> h(H, false), w(W, false);
	REP(i, H)REP(j, W) {
		if (a[i][j] == '#') {
			h[i] = true;
			break;
		}
	}
	REP(j, W)REP(i, H) {
		if (a[i][j] == '#') {
			w[j] = true;
			break;
		}
	}
	REP(i, H){
		if (h[i]) {
			REP(j, W) {
				if (w[j]) {
					cout << a[i][j];
				}
			}
			cout << "\n";
		}
	}

	return 0;
}