#include <bits/stdc++.h>
	
using namespace std;
 
#define int long long
 
#define PB	push_back
#define ALL(x)	(x).begin(), (x).end()
#define ALLR(x)	(x).rbegin(), (x).rend()
#define MP	make_pair
 
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0)
 
typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef unsigned long long ull;
 
const int INF = LONG_LONG_MAX;
const int NINF = LONG_LONG_MIN/2;
const double PI = 3.141592653589793238;

struct segtree {
	int size;
	vi values;
	vi mins;
	
	void init(int n) {
		size = 1;
		while (size <= n) size *= 2;
		values.assign(2*size, 0ll);
		mins.assign(2*size, 0ll);
	}
	
	void build(vi& a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			values[x] = a[lx];
			return;
		}
		
		int m = (lx + rx) / 2;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		
		values[x] = values[2*x + 1] + values[2*x + 2];
	}
	
	void build(vi& a) {
		build(a, 0, 0, size);
	}
	
	void add(int l, int r, int v, int x, int lx, int rx) {
		if (rx <= l || lx >= r) {
			return;
		}
		if (lx >= l && rx <= r) {
			values[x] += v;
			mins[x] += v;
			return;
		}
		
		int m = (lx + rx) / 2;
		add(l, r, v, 2*x + 1, lx, m);
		add(l, r, v, 2*x + 2, m, rx);
		mins[x] = std::min(mins[2*x + 1], mins[2*x + 2]) + values[x];
	}
	
	void add(int l, int r, int v) {
		add(l, r, v, 0, 0, size);
	}

	int min(int l, int r, int x, int lx, int rx) {
		if (rx <= l || lx >= r) {
			return INF;
		}
		if (lx >= l && rx <= r) {
			return mins[x];
		}
		
		int m = (lx + rx) / 2;
		int m1 = min(l, r, 2*x + 1, lx, m);
		int m2 = min(l, r, 2*x + 2, m, rx);
		return std::min(m1, m2) + values[x];
	}
	
	int min(int l, int r) {
		return min(l, r, 0, 0, size);
	}
};

int MOD = 1000000000+7;
bool multi = false;
struct Solve {
	string endl = "\n";
	
	Solve() {
		int n;
		cin >> n;
		vi a(n);
		for (int& x: a) cin >> x;
		
		vi prefix;
		prefix.push_back(0);
		for (int i = 0; i < n; i++) {
			prefix.push_back((prefix.back()+a[i])%MOD);
		}
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += prefix[i-1]*a[i-1];
			ans %= MOD;
		}
		cout << ans << endl;
	}
};

int32_t main() {
	FAST_IO;
	
	int T=1;
	if (multi)
		cin >> T;
	for (int i = 1; i <= T; i++) {
		Solve me;
	}
}
// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
