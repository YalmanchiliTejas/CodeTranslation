/*******
 *   Author: Quamputer
 *   
 * ******/
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

#ifdef KILLBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
 
const int INF = LONG_LONG_MAX/2;
const double PI = 3.141592653589793238;
const int MOD = 998244353;

//MODULAR ARITHMATIC
const int mmod = 998244353 ;

int add(int a, int b, int m=mmod) {
	return (a%m + b%m)%m;
}

int sub(int a, int b, int m=mmod) {
    return (a%m - b%m + m)%m;
}

int mul(int a, int b, int m=mmod) {
	return ((a%m) * (b%m) % m);
}

int pwr(int a, int b, int m=mmod) {
    a %= m;
    int r = 1;
    while (b) {
		if (b&1) r = r*a%m;
		b >>= 1;
		a = a*a%m;
    }
    return r;
}

int inv(int a, int m=mmod) {
	return pwr(a, m-2, m);
}

bool many = false;
struct Solve {
	string endl = "\n";
	
	Solve() {
		//cout << pwr(2, 16, 1001) << endl;
		int n, x, m;
		cin >> n >> x >> m;
		
		vi a(1000001);
		a[1] = x;
		for (int i = 2; i <= 1000000; i++) {
			a[i] = (a[i-1]*a[i-1])%m;
		}
		
		
		set<int> s;
		
		int rep = -1;
		for (int i = 1; i < (int)a.size(); i++) {
			if (s.count(a[i]) != 0) {
				rep = a[i];
				break; 
			}
			s.insert(a[i]);
		}
		
		vi b;
		
		for (int i = 1; i < (int)a.size(); i++) {
			if (a[i] == rep) {
				b.PB(i);
			}
			if ((int)b.size() == 2) break;
		}
		b[1] -= 1;
		int len = b[1] - b[0] + 1;
		
		int cnt = (n-b[0]+1) / (len);
		
		int rem = (n-b[0]+1) % len;
		
		int sum = 0;
		
		for (int i = b[0]; i <= b[1]; i++) {
			sum += a[i];
		}
		
		//~ for (int i = 0; i < 100; i++) cout << a[i] << ' ';
		//~ cout << endl;
		//~ debug(rep);
		//~ debug(b);
		//~ debug(len, cnt, rem);
		
		sum *= cnt;
		
		for (int i = 1; i < b[0]; i++) sum += a[i];
		for (int i = 0; i < rem; i++) sum += a[b[0] + i];
		
		cout << sum << endl;
	}
};

signed main() {
#if !defined(KILLBUG)
	FAST_IO;
#endif

	int CASES=1;
	if (many)
		cin >> CASES;
	for (int i = 1; i <= CASES; i++) {
		Solve me;
	}
}
// g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
