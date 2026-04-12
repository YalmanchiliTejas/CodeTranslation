#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
	EACH(x,vec) is >> x;
	return is;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2>& p) {
	return os << p.first << " " << p.second;
}
/*
template<class... T>
ostream& operator<<(ostream& os, tuple<T...>& t) {
	for (size_t i = 0; i < tuple_size< tuple<T...> >::value; ++i) {
		if (i) os << " ";
		os << get<0>(t);
	}
	return os;
}
*/
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
	REP(i,vec.size()) {
		if (i) os << " ";
		os << vec[i];
	}
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
	REP(i,vec.size()) {
		if (i) os << endl;
		os << vec[i];
	}
	return os;
}

int H, W, M;
vector<string> m;
bool inRange(P p) {
	int x, y; tie(x, y) = p;
	return 0 <= x && x < W && 0 <= y && y < H;
}
bool isWall(P p) {
	int x, y; tie(x, y) = p;
	return m[y][x] == '#';
}
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
vector<P> bfs(P s, P t) {
	map<P, bool> used;
	map<P, P> prevV;
	queue<P> Q; Q.push(s); used[s] = true;
	while ( !Q.empty() ) {
		P p = Q.front(); Q.pop();
		REP(d, 4) {
			int nx = p.first + dx[d], ny = p.second + dy[d];
			P np(nx, ny);
			if ( inRange(np) && !isWall(np) && !used[np] ) {
				used[np] = true;
				prevV[np] = p;
				Q.push(np);
			}
		}
	}
	vector<P> res;
	for (P p = t; p != s; p = prevV[p]) {
		res.pb(p);
	}
	reverse(ALL(res));
	return res;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> H >> W >> M;
	m = vector<string>(H);
	cin >> m;
	vector< vector<ll> > keep(H, vector<ll>(W));
	vector< vector<ll> > on(H, vector<ll>(W));
	vector< vector<ll> > off(H, vector<ll>(W));
	cin >> keep >> on >> off;
	vector<P> tasks;
	REP(i, M) {
		int x, y; cin >> y >> x;
		tasks.pb(P(x, y));
	}
	vector<P> v; v.pb(tasks[0]);
	REP(i, M-1) {
		vector<P> path = bfs(tasks[i], tasks[i+1]);
		EACH(p, path) v.pb(p);
	}
	map<P, vector<int> > task;
	REP(i, v.size()) {
//		cout << v[i] << endl;
		task[v[i]].pb(i);
	}
	ll ans = 0;
	map<P, bool> state;
	REP(i, v.size()) {
		P& p = v[i];
		int x, y; tie(x, y) = p;
		if (!state[p]) {
			state[p] = true;
			ans += on[y][x];
		}
		auto it = upper_bound(ALL(task[p]), i);
		if (it == task[p].end()) {
			state[p] = false;
			ans += off[y][x];
		}
		else {
			int t2 = *it;
			int t = t2 - i;
			if (keep[y][x] * t <= off[y][x] + on[y][x]) {
				ans += keep[y][x] * t;
//				cout << t << endl;
			}
			else {
				state[p] = false;
				ans += off[y][x];
			}
		}
	}
	cout << ans << endl;
}