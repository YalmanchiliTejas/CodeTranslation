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

LL n;
vector<pair<LL, LL>> p;

int main() {
	cin >> n;
	inc(i, n) {
		LL x, y;
		cin >> x >> y;
		
		p.EB(min(x, y), max(x, y));
	}
	
	sort(ALL(p));
	LL xmin = p[0].FI, xmax = p[n - 1].FI;
	
	inc(i, n) { swap(p[i].FI, p[i].SE); }
	sort(ALL(p));
	LL ymin = p[0].FI, ymax = p[n - 1].FI;
	
	PQ<pair<LL, LL>> q;
	inc(i, n) { q.push(p[i]); }
	
	LL ans = (xmax - xmin) * (ymax - ymin);
	while(! q.empty()) {
		auto e = q.top(); q.pop();
		if(e.FI <= e.SE) { break; }
		q.emplace(e.SE, e.FI);
		
		setmin(ymin, e.SE);
		setmax(xmax, e.FI);
		ymax = q.top().FI;
		
		setmin(ans, (xmax - xmin) * (ymax - ymin));
	}
	
	cout << ans << endl;
	
	return 0;
}
