#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
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
#define RREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define INF10 1001001001 
#define INF5 100000
#define EPS 1e-10


int main() {
	int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

	int cnt = 0;

	while (X > 0 && Y > 0) {
		X--;
		Y--;
		cnt += min(A + B, 2 * C);
	}
	
	while (X > 0) {
		X--;
		cnt += min(A, 2 * C);
	}
	while (Y > 0) {
		Y--;
		cnt += min(B, 2 * C);
	}
	print(cnt);




	return 0;
}
