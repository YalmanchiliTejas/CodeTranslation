#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>

typedef std::uint64_t u64;
typedef std::int64_t  i64;
typedef std::uint32_t u32;
typedef std::int32_t  i32;

using namespace std;

#define swap(a, b)    do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while(0)
#define repd(i, a, b) for(typeof(b) i = a; i < (b); ++i)
#define rep(i, n)     repd(i, 0, n)
#define dump(x)       cerr << #x << " = " << (x) << endl
#define debug(x)      cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl

#define YesNo(x) if(x) cout << "Yes" << endl; else cout << "No" << endl;
#define YESNO(x) cout << ((x) ? "YES" : "NO") << endl

bool graph[8][8];

u64 n;

/* 
 *  s: 始点の番号
 *  v: v[i] = iをすでに通っているかどうか
 */
u64 f(u64 s, vector<bool> v) {
	debug(s);
	bool all_visited = true;
	rep(i, n) {
		if(v[i] == false) {
			all_visited = false;
		}
	}
	if(all_visited) {
		cerr << "All nodes are visited." << endl;
		return 1;
	}

	u64 ret = 0;
	rep(i, n) {
		 /* s から i に行けない、もしくは i をすでに通っていれば飛ばす */
		if(graph[s][i] == false) {
			cerr << i << " is skipped. (graph[" << s << "][" << i << "] == false)" << endl;
			continue;
		}

		if(v[i]) {
			cerr << i << " is skipped. (v[" << i << "] == true)" << endl;
			continue;
		}

		/* s から i に行けて、i をまだ通っていなければ探索する */
		cerr << "call: " << s << " -> " << i << endl;
		v[i] = true;
		ret += f(i, v);
		v[i] = false;
	}

	return ret;
}

int main(int argc, const char* argv[]) {
	u64 m;
	cin >> n >> m;

	rep(i, 8) {
		rep(j, 8) {
			graph[i][j] = false;
		}
	}

	rep(i, m) {
		u64 a, b;
		cin >> a >> b;
		graph[--a][--b] = true;
		graph[b][a] = true;
	}

	rep(i, n) {
		rep(j, n) {
			cerr << graph[i][j];
		}
		cerr << endl;
	}

	vector<bool> v(n, false);
	v[0] = true;

	cout << f(0, v) << endl;

	return 0;
}
