#include <bits/stdc++.h>

using namespace std;

#define PB	push_back
#define ALL(x)	(x).begin(), (x).end()
#define ALLR(x)	(x).rbegin(), (x).rend()
#define MP	make_pair

#define debug(args...) { string _s = #args; replace(ALL(_s), ',', ' '); stringstream ss(_s); cerr << endl;_debug(ss, args); }
#define _rg auto it = next(v.begin()); it != v.end(); it++
#define _input ostream& operator <<(ostream& out

template<typename T, typename U>
_input, const pair<T, U>& p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

#define cont(c) template<typename T> _input, const c<T>& v) { \
					if (v.empty()) return out; \
					out << "[" << *v.begin(); \
					for (_rg) out << ", " << *it; \
					out << "]"; return out; \
				}
				
#define cont2(c) template<typename T, typename U> _input, const c<T, U>& v) { \
					if (v.empty()) return out; \
					out << "[" << *v.begin(); \
					for (_rg) out << ", " << *it; \
					out << "]"; return out; \
				}

cont(vector) cont(set) cont(multiset) cont(queue) cont2(map)

template<typename T, size_t n, typename= enable_if_t<!is_same<T, char>::value>>
_input, const T(&v)[n]) {
	if (n == 0) return out;
	out << "[" << v[0];
	for (int i = 1; i < (int)n; i++) out << ", " << v[i];
	out  << "]"; return out;
}

template<typename T, typename... Ts>
void _debug(stringstream& ss, const T &arg) {
	string name; ss >> name;
	cerr << name << " = " << arg << endl;
}

template<typename T, typename... Ts>
void _debug(stringstream& ss, const T& arg, const Ts&... args) {
	string name; ss >> name; 
	cerr << name << " = " << arg << ", ";
	if (is_class<T>::value || is_array<T>::value) cerr << endl;
	_debug(ss, args...);
}

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0)

#define int long long int

typedef pair<int, int> ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int> vi;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef unsigned long long ull;

const int INF = LONG_LONG_MAX>>1;
const int NINF = LONG_LONG_MIN/2;
const double PI = 3.141592653589793238;

//MODULAR ARITHMATIC
const int mmod = 1000000007;

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

void add_self(int& a, int b) {
	a = add(a, b);
}

int32_t main() {
	FAST_IO;
	
	//PROBLEM: count number which are at most K and sum of digit is D
	
	string K;
	int D;
	cin >> K >> D;
	
	vvi dp(D+1, vi(2));
	// dp[i][j] = count of numbers with digit sum i so far and j represent smaller digit already choosen
	dp[0][0] = 1;
	for (int i = 0; i < (int)K.size(); i++) {
		vvi new_dp(D+1, vi(2));
		for (int sum = 0; sum <= D; sum++) {
			for (int already = 0; already < 2; already++) {
				for (int dig = 0; dig < 10; dig++) {
					if (dig > K[i]-'0' && !(already)) break;
					add_self(new_dp[(sum+dig)%D][already || dig < K[i]-'0'], dp[sum][already]); 
				}
			}
		}
		dp = new_dp;
	}
	int ans = add(dp[0][true], dp[0][false]);
	ans = sub(ans, 1);
	cout << ans << endl;
}

// g++ -Wall -Wextra -Wshadow -fsanitize=undefined -std=c++17
