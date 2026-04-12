#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

#define EPS 1e-14
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) FOR(i, 0, n)
#define PI 2*acos(0.0)
#define ALL(a) (a).begin(),(a).end()
#define DEBUG(x) cout<<#x <<": "<< x << "\n"
#define DEBUG_ARR(a) REP(i, size(a)){ cout << #a << "[" << i << "]: " << a[i] << "\n"; }
const int VX[] = { 0, 1, 0, -1 };
const int VY[] = { 1, 0, -1, 0 };
const long MOD = 1000000007;

int main() {
	//	--- I/O 高速化 ---
	cin.tie(0);
	ios::sync_with_stdio(false);
	// --- ここまで ---

	int X, Y, Z, ans = 0;
	cin >> X >> Y >> Z;

	X -= Z;
	ans = X / (Y + Z);

	cout << ans << endl;

	return 0;
}

