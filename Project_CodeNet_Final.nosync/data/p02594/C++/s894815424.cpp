#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// macros
#define int long long 
#define ll long long 
#define ld long double
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define sz(x) ((int)((x).size()))

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
  return (b ? "1" : "0");
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
 
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

template <typename T1, typename T2>
inline auto mini(T1 a, T2 b) { return (a < b ? a : b); }
template<typename T, typename... Args>
inline auto mini(T a, Args... args) { return mini(a, mini(args...)); }
template <typename T1, typename T2>
inline auto maxi(T1 a, T2 b) { return (a > b ? a : b); }
template<typename T, typename... Args>
inline auto maxi(T a, Args... args) { return maxi(a, maxi(args...)); }
template<typename T>
T gcd(T a, T b) { if(a==0 or b==0) return a+b; return gcd(b, a%b) ; }
template<typename T>
T lcm(T a, T b) { if(a==0 or b==0) return 0; return a/gcd(a, b)*b; }

// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // use mt19937_64 for 64 bit

// constants
const long double eps = LDBL_EPSILON;
const int inf = 1e15;
const int modn = 1e9+7;
const int maxn = 2e5+3;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
	int x;
	cin >> x;
	if(x >= 30) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
    return 0;
}