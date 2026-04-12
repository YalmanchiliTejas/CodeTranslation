#include<iostream>
#include<iomanip>
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
#include<deque>
#include<tuple>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> H(N);
	REP(i, N) cin >> H[i];
	int res = 1;
	FOR(i, 1, N) {
		bool flag = true;
		REP(j, i) {
			if (H[j] > H[i]) flag = false;
		}
		if (flag) res++;
	}
	cout << res << endl;

	return 0;
}
