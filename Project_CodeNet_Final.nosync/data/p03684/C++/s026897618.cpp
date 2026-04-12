#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define  inc(i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define  dec(i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define UB upper_bound
#define LB lower_bound
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)
#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)

template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

LL n, x[100000], y[100000], ans;
pair<LL, LL> px[100000], py[100000];
vector<array<LL, 3>> e;

const int N = 100001;
vector<int> v[N];
int id[N];
int unit, cn;
void init() {
	inc(i, n) { v[i].PB(i); id[i] = i; }
	unit = n;
	cn = n;
}
void unite(int xx, int yy) {
	int x = id[xx], y = id[yy];
	if(x == y) { return; }
	cn--;
	if(v[x].size() > v[y].size()) { swap(x, y); }
	if(v[x].size() == 1) { unit--; }
	if(v[y].size() == 1) { unit--; }
	
	dec(i, v[x].size()) {
		id[ v[x][i] ] = y;
		v[y].PB(v[x][i]);
		v[x].pop_back();
	}
}

int main() {
	cin >> n;
	inc(i, n) { cin >> x[i] >> y[i]; }
	
	inc(i, n) {
		px[i] = MP(x[i], i);
		py[i] = MP(y[i], i);
	}
	sort(px, px + n);
	sort(py, py + n);
	
	inc(i, n - 1) {
		e.PB( { px[i + 1].FI - px[i].FI, px[i].SE, px[i + 1].SE } );
		e.PB( { py[i + 1].FI - py[i].FI, py[i].SE, py[i + 1].SE } );
	}
	sort(ALL(e));
	
	init();
	inc(i, e.size()) {
		if(id[ e[i][1] ] != id[ e[i][2] ]) {
			unite(e[i][1], e[i][2]);
			ans += e[i][0];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
