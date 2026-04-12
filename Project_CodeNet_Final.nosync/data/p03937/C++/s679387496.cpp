#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <fstream>
#include <iomanip>
using namespace std;
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str(); }
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,(n))
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = INT_MAX / 2;
const int MOD = 1000000007;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int main () {
	int H, W;
	cin >> H >> W;
	vs A(H);
	int count = 0;
	REP(i, H) {
		cin >> A[i];
		REP(j, W) {
			if (A[i][j] == '#') {
				count++;
			}
		}
	}

	if (count == H + W - 1) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}