#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define print(x) cout<<(x)<<endl
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define INF10 1001001001 
#define INF5 100000
#define EPS 1e-10


int main() {
	int N; cin >> N;
	vector<int>H(N);
	REP(i, N) cin >> H[i];
	int mx = 0;
	int cnt = 0;
	REP(i, N) {
		if (H[i] >= mx) {
			mx = H[i];
			cnt++;
		}
	}
	print(cnt);


	return 0;
}
