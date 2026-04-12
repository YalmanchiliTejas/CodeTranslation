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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
set <int> lin, col;
map <int, int> vall, valc;
int x[N], y[N], n, use[2 * N];
long long ans;
vector <pair<int, int> > v[2 * N];
vector <int> l, c;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		lin.insert(x[i]);
		col.insert(y[i]);
	}

	int nr = 0;
	for(auto i : lin) vall[i] = ++nr, l.push_back(i);
	for(auto i : col) valc[i] = ++nr, c.push_back(i);

	for(int i = 1; i < l.size(); i++) {
		v[vall[l[i - 1]]].push_back({l[i] - l[i - 1], vall[l[i]]});
		v[vall[l[i]]].push_back({l[i] - l[i - 1], vall[l[i - 1]]});
	}

	for(int i = 1; i < c.size(); i++) {
		v[valc[c[i - 1]]].push_back({c[i] - c[i - 1], valc[c[i]]});
		v[valc[c[i]]].push_back({c[i] - c[i - 1], valc[c[i - 1]]});
	}

	for(int i = 1; i <= n; i++) {
		v[vall[x[i]]].push_back({0, valc[y[i]]});
		v[valc[y[i]]].push_back({0, vall[x[i]]});
	}

	use[1] = 1;
	priority_queue <pair<int, pair<int, int> > > pq;

	for(auto i : v[1]) pq.push({-i.st, {1, i.nd}});

	while(!pq.empty()) {
		pair<int, int> pp = pq.top().nd;
		int val = -pq.top().st;
		int cand = -1;
		pq.pop();
		if(!use[pp.st]) cand = pp.st;
		else if(!use[pp.nd]) cand = pp.nd;

		if(cand != -1) {
			use[cand] = 1;
			for(auto i : v[cand]) pq.push({-i.st, {cand, i.nd}});
			ans += val;
		}
	}
	cout << ans << '\n';

}
