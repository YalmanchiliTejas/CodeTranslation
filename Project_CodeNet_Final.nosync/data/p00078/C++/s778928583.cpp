#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define ERASE(v,i) (v).erase(remove(all(v),i),(v).end())
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
#define LINE cerr<<"LINE: "<<__LINE__<<endl;

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T> void preview(T a,T b){for(T it=a;it!=b;++it)cerr<<*it<<" ";cerr<<endl;}

const int INF = 100000000;
const double PI = acos(-1.0), EPS = 1e-10;

int field[20][20];
int num;

void pv(int n) {
	rep(i,n) preview(field[i], field[i] + n);
}

bool check(int n) {
	bool f = false;
	rep(y,n) rep(x,n) if(field[y][x] == 0) f = true;
	return f;
}

P put(int ny, int nx, int n) {
	if(n <= nx) {
		return put(ny, 0, n);
	}
	else if(nx < 0) {
		return put(ny, n - 1, n);
	}
	else if(n <= ny) {
		return put(0, nx, n);
	}
	else if(field[ny][nx] != 0) {
		return put(ny + 1, nx - 1, n);
	}
	else {
		field[ny][nx] = num;
		return mp(ny, nx);
	}
}

int main() {
	for(int n; scanf(" %d", &n), n;) {
		memset(field, 0, sizeof field);
		int py = (n + 1) / 2;
		int px = (n + 1) / 2 - 1;

		field[py][px] = 1;
		num = 2;
		while(check(n)) {
			int nx = px + 1;
			int ny = py + 1;
			P next = put(ny, nx, n);
			py = next.first;
			px = next.second;
#if 0
			pv(n);
			cerr << endl;
#endif

			++num;
		}
		rep(y,n) {
			rep(x,n) {
				printf("%4d", field[y][x]);
			}
			puts("");
		}
	}
	return 0;
}