#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef unsigned long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 500 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

vector<int> s, t;
vector<ll> u, v;
int n;
ll mat[maxN][maxN];

void no() {
	cout << "-1\n"; exit(0);
}

void transp() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < i; j++) swap(mat[i][j], mat[j][i]);
	swap(s, t);
	swap(u, v);
}

void cumplands() {
	for(int i = 0; i < n; i++) {
		if(s[i]) continue;
		ll crv = ~(ll(0));
		for(int j = 0; j < n; j++) crv &= mat[i][j];
		if(crv != u[i]) no();
	}
}

const int bts = 64;
const ll un = 1;

bool isColGood(int w) {
	ll ret = ~(ll(0));
	for(int i = 0; i < n; i++)
		ret &= mat[i][w];
	return ret == v[w];
}

void otsolv() {
	vector<int> inds, tbl(bts), frq(bts);
	vector<ll> msks(n);
	for(int i = 0; i < n; i++)
		if(!t[i]) inds.push_back(i);
	for(int i = 0; i < n; i++) {
		if(!s[i]) continue;
		ll crv = 0;
		for(int j = 0; j < n; j++) crv |= mat[i][j];
		if((crv | u[i]) != u[i]) no();
		crv = u[i] ^ crv;
		msks[i] = crv;
		if(!crv) continue;
		if(inds.empty()) no();
		for(int j = 0; j < bts; j++)
			if(un << j & crv) frq[j]++;
	}

	for(int i = 0; i < n; i++) {
		if(!msks[i]) continue;
		for(int j = 0; j < bts; j++) {
			if((un << j & msks[i]) && frq[j] == 1) {
				int good = -1;
				for(auto w: inds) {
					mat[i][w] ^= un << j;
					if(isColGood(w)) {good = w; break;}
					mat[i][w] ^= un << j;
				}
				if(good == -1) no();
				msks[i] ^= un << j;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(!msks[i]) continue;
		for(int k = 0; k < bts; k++) {
			if(un << k & msks[i]) {
				mat[i][inds[tbl[k]]] |= un << k;
				tbl[k] = (tbl[k] + 1) % inds.size();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	#endif

	cin >> n;
	s.resize(n);
	t.resize(n);
	u.resize(n);
	v.resize(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < n; i++) cin >> t[i];
	for(int i = 0; i < n; i++) cin >> u[i];
	for(int i = 0; i < n; i++) cin >> v[i];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(!s[i]) mat[i][j] |= u[i];
			if(!t[j]) mat[i][j] |= v[j];
			if(s[i] && t[j]) mat[i][j] = u[i] & v[j];
		}
	}

	for(int u = 0; u < 2; u++, transp()) cumplands();
	for(int u = 0; u < 2; u++, transp()) otsolv();
	for(int u = 0; u < 2; u++, transp()) cumplands();

	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < n; j++) cout << mat[i][j] << ' ';
}

