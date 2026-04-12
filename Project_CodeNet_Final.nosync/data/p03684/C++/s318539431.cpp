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
pair<LL, LL> ppx[100000], ppy[100000];
array<LL, 3>  px[100000],  py[100000];

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
		ppx[i] = MP(x[i], i);
		ppy[i] = MP(y[i], i);
	}
	sort(ppx, ppx + n);
	sort(ppy, ppy + n);
	
	inc(i, n - 1) {
		px[i] = { ppx[i + 1].FI - ppx[i].FI, ppx[i].SE, ppx[i + 1].SE };
		py[i] = { ppy[i + 1].FI - ppy[i].FI, ppy[i].SE, ppy[i + 1].SE };
	}
	sort(px, px + n - 1);
	sort(py, py + n - 1);
	
	init();
	int ix = 0, iy = 0;
	while(true) {
		if(ix == n - 1 && iy == n - 1) { break; }
		
		bool flag;
		     if(iy == n - 1) { flag = true; }
		else if(ix == n - 1) { flag = false; }
		else { flag = (px[ix][0] <= py[iy][0]); }
		if(flag) {
			if(id[ px[ix][1] ] != id[ px[ix][2] ]) {
				unite(px[ix][1], px[ix][2]);
				ans += px[ix][0];
			}
			ix++;
		} else {
			if(id[ py[iy][1] ] != id[ py[iy][2] ]) {
				unite(py[iy][1], py[iy][2]);
				ans += py[iy][0];
			}
			iy++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
