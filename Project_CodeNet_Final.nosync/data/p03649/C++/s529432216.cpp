#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;

long long a[N], b[N], n;

bool ok(long long nr) {
	long long b[N];
	for(long long i = 1; i <= n; i++) b[i] = a[i] + nr;

	long long req = 0;
	dbg(nr);
	dbg_v(b, n + 1);
	for(long long i = 1; i <= n; i++) {
		req += b[i] / (n + 1);
		req += (b[i] % (n + 1) == n);
	}
	dbg(req);
	return (req <= nr);
}


long long cb(long long l, long long r) {
	while(l != r) {
		long long mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

void scad(long long * a, long long n) {
	long long mx = 1;
	for(long long i = 1; i < n; i++)
		if(a[i] > a[mx])
			mx = i;
	a[mx] -= n;
}

long long simulate(priority_queue <long long> pq) {
	long long ret = 0;
	while(pq.top() + ret >= pq.size()) {
		long long x = pq.top() - pq.size() - 1;
		pq.pop();
		pq.push(x);
		ret++;
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	long long s = 0;
	for(long long i = 1; i <= n; i++) cin >> a[i], s += a[i];


	long long nrmin = s - 2 * n * n;
	if(nrmin > 0) {
		for(long long i = 1; i <= n; i++) a[i] += nrmin;
			
		long long op = 0;
		for(long long i = 1; i <= n; i++) {
			if(a[i] > 2 * n) {
				a[i] -= 2 * n;
				op += a[i] / (n + 1);
				a[i] = a[i] % (n + 1) + 2 * n;
			}
		}
		while(op < nrmin) scad(a, n + 1), op++;
	}
	priority_queue <long long> pq;
	for(long long i = 1; i <= n; i++) 
		pq.push(a[i]);
	cout << max(nrmin, 0LL) + simulate(pq);
}	
