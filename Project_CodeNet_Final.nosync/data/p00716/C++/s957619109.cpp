#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
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

using namespace std;

inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EACH(t,i,c) for(t::iretator i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

const double EPS = 1e-10;

int main() {
	int m;
	cin >> m;

	REP(i, m) {
		int shoki, nennsuu, shurui;
		cin >> shoki >> nennsuu >> shurui;
		vi result(shurui, shoki);

		REP(j, shurui) {
			int fukuri, tesuuryou;
			double nennritu;
			cin >> fukuri >> nennritu >> tesuuryou;

			int rishi = 0;
			REP(k, nennsuu) {
				if(fukuri) {
					result[j] += (result[j]*nennritu-tesuuryou);

				} else {
					rishi += result[j]*nennritu;
					result[j] -= tesuuryou;
				}
			}
			result[j] += rishi;
		}

		int max = 0;
		REP(j, result.size()) {
			if(max < result[j]) {
				max = result[j];
			}
		}

		cout << max << endl;
	}
}