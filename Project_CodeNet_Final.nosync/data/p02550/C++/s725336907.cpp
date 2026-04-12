#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

template<typename T>
string to_string(const vector<T>& vc, int w) {
	if(vc.empty()) return "";
	if(w + 1 == vc.size()) return to_string(vc[w]);
	return to_string(vc[w]) + "," + to_string(vc, w + 1);
}

template<typename T>
string to_string(const vector<T>& vc) {
	return "{" + to_string(vc, 0) + "}";
}

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

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	#endif

	ll n, x, m;
	cin >> n >> x >> m;

	vector<ll> nms({x});
	map<ll, int> mp;
	mp[x] = 0;

	while(1) {
		x = x * x % m;
		if(mp.count(x))
			break;
		mp[x] = nms.size();
		nms.push_back(x);
	}

	if(n <= nms.size()) {
		cout << accumulate(nms.begin(), nms.begin() + n, 0LL) << '\n'; return 0;
	}

	int w = mp[x];
	ll tmp = accumulate(nms.begin(), nms.begin() + w, 0LL);
	n -= w;
	ll cycsz = int(nms.size()) - w;
	ll tot = accumulate(nms.begin() + w, nms.end(), 0LL);
	ll ende = accumulate(nms.begin() + w, nms.begin() + w + n % cycsz, 0LL);
	cout << (n / cycsz) * tot + ende + tmp << '\n';
}

