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

bool isLeft(char c) {
	switch(c) {
	case 'q':
	case 'a':
	case 'z':
	case 'w':
	case 's':
	case 'x':
	case 'e':
	case 'd':
	case 'c':
	case 'r':
	case 'f':
	case 'v':
	case 't':
	case 'g':
	case 'b':
		return true;
	default:
		return false;
	}
}



int main() {
	string str;

	while(cin >> str, str != "#") {
		bool lastLeft;
		int num = 0;

		lastLeft = isLeft(str[0]);

		FOR(i, 1, str.size()) {
			if(lastLeft != isLeft(str[i])) {
				num++;
			}
			lastLeft = isLeft(str[i]);
		}

		cout << num << endl;
	}
}