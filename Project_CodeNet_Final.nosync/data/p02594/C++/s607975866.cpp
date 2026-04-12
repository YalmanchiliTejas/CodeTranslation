#if 1
#pragma GCC target("avx")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
//#define int long long

#if defined (_MSC_VER)
#pragma comment (linker, "/STACK:256000000")
#define _CRT_SECURE_NO_WARNINGS
#include <__msvc_all_public_headers.hpp>
#define dbg(x_) cout << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cout << #mp << ":" << endl; for(auto i = mp.begin(); i != mp.end(); ++i){ cout << i->first << ":" << i->second << endl; }
#define dbgarr(n, m, arr) rep(i, n){ rep(j, m){ cout << arr[i][j] << " "; }cout << endl; }
#define dbgdp(n, arr) rep(i, n){ cout << arr[i] << " "; }cout << endl;
#define dbgmint(n, arr) rep(i, n){ cout << arr[i].x << " "; }cout << endl;
#define dbgarrmint(n, m, arr) rep(i, n){ rep(j, m){ cout << arr[i][j].x << " "; }cout << endl; }
#define __builtin_popcount(n) __popcnt(n)
#else
using f80 = __float80;
#define dbg(...) 42
#define dbgmap(...) 42
#define dbgarr(...) 42
#define dbgdp(...) 42
#define dbgmint(...) 42
#define dbgarrmint(...) 42
#endif

#if 1
using ll = long long;
using ull = unsigned long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const long double PI = 3.141592653589793238462643383279;
#define endl '\n'
#define rep(i, n) for(ull i = 0; i < ull(n); ++i)
#define repi(i, a, b) for(ull i = ull(a); i < ull(b); ++i)
#define rrep(i, n) rrepi(i, n - 1, 0 - 1)
#define rrepi(i, a, b) for(ll i = ll(a); i > ll(b); --i)
#define vrep(x, arr) for(auto &x : arr)
#define ITR(x, c) for(__typeof(c.begin()) x = c.begin(); x != c.end(); ++x)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define SORT(obj) sort((obj).begin(), (obj).end())
#define RSORT(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define UNIQUE(v) SORT(v); v.erase(unique(v.begin(), v.end()), v.end())
#define show(v) rep(i, v.size()){ cout << v[i] << " "; }cout << endl
#define showl(v) rep(i, v.size()){ cout << v[i] << endl; }cout << endl
#define MAX(x) * max_element(ALL(x))
#define MIN(x) * min_element(ALL(x))
#define EPS (1e-7)
//#define INF (1e9)
//#define PI acos(-1)L)
#define SZ(x) ((ll)(x).size())
#define SUM(v, i) accumulate(ALL(v), i)
#define nSUM(n) ((n)+1) * (n) / 2　//1〜nまでの総和を求める式
#define debugl(a) cout << a << endl
#define debug(a) cout << a << " "
#define push_buck emplace_back
#define PB push_back
#define MP make_pair
#define rad_to_deg(rad) (((rad) / 2 / PI) * 360)
#define deg_to_rad(deg) (((deg) / 360) * 2 * PI)
using vi = vector<int>;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vi inVInt(){ int n; cin >> n; vi v(n); rep(i, n) cin >> v[i]; return v; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b < a){ a = b; return 1; } return 0; }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
inline void print(){ cout << endl; }
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest){ cout << first << ' '; print(rest...); }
struct fastIO{ fastIO(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fastIO;
//template <typename... Args>void IN(Args& ... args) {cin >>args;IN(args...);return;} //まとめて入力　IN(a,b,c,d...)

ull gcd(ull a, ull b){ return b?gcd(b, a % b):a; }//最大公約数
ull lcm(ull a, ull b){ return a * b / gcd(a, b); }	//最小公倍数

bool IsPrime(int num){
	if(num < 2) return false;
	else if(num == 2) return true;
	else if(num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = std::sqrt(num);
	for(int i = 3; i <= sqrtNum; i += 2){
		if(num % i == 0)return false;		// 素数ではない
	}
	return true;	// 素数である
}

// n個の数字の最小公倍数
int nlcm(vector<int> numbers){
	int res;
	res = numbers[0];
	for(int i = 1; i < numbers.size(); i++)res = lcm(res, numbers[i]);
	return res;
}

 // n個の数字の最大公約数
int ngcd(vector<int> a){
	int res;
	res = a[0];
	for(int i = 1; i < a.size() && res != 1; i++) res = gcd(a[i], res);
	return res;
}

int digsum(int n){
	int res = 0;
	while(n > 0){
		res += n % 10; //桁和
		// res++;       桁数
		n /= 10;
	}
	return res;
}

struct mint{
	ll x;
	mint(ll x = 0):x(x %MOD){}
	mint &operator+=(const mint a){
		if((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint &operator-=(const mint a){
		if((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint &operator*=(const mint a){
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint a) const{
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const{
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const{
		mint res(*this);
		return res *= a;
	}
	mint pow(ll t) const{
		if(!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if(t & 1) a *= *this;
		return a;
	}

	// for prime MOD
	mint inv() const{
		return pow(MOD - 2);
	}
	mint &operator/=(const mint a){
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const{
		mint res(*this);
		return res /= a;
	}
};

mint ncr(ll n, ll a){
	mint x = 1, y = 1;
	//rep(i, a) {
	for(int i = 0; i < a; ++i){
		x *= n - i;
		y *= i + 1;
	}
	return x / y;
}

// a^n MOD を計算する
long long modpow(long long a, long long n, long long mod){
	long long res = 1;
	while(n > 0){
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
//繰り返し二乗法
long long pow2(long long a, long long n){
	long long res = 1;
	while(n > 0){
		if(n & 1) res = res * a;
		a = a * a;
		n >>= 1;
		dbg(res);
	}
	return res;
}

//素因数分解
map<ll, ll> GetPrimeFactors(ll n){
	map<ll, ll> mp;
    // dived by 2, 3, 5, ...
	while(n % 2 == 0){
		++mp[2];
		n /= 2;
	}
	for(int i = 3; i * i <= n; i += 2){
		while(n % i == 0){
			++mp[i];
			n /= i;
		}
	}
	if(n != 1) ++mp[n];
	return mp;
}

//約数全列挙
vector<int> enum_div(int n){
	vector<int> ret;
	for(int i = 1; i * i <= n; ++i){
		if(n % i == 0){
			ret.push_back(i);
			if(i != 1 && i * i != n) ret.push_back(n / i);
		}
	}
	return ret;
}

//約数全列挙 set ver
set<ll> listDivisors(ll n){   // set版
	set<ll> divs;
	repi(i, 1, (ll)(std::sqrt(n) + 1)){
	//FOR( i , 1 , ( ll )( sqrt( n ) + 1 ) ) {   // {1, n} を除く場合は2番目の引数を 2 にする
		if(n % i == 0){
			divs.insert(i);
			divs.insert(n / i);
		}
	}
	return divs;
}

//乱数生成
unsigned int randInt(){
	static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
	unsigned int tt = (tx ^ (tx << 11));
	tx = ty; ty = tz; tz = tw;
	return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

//文字列中に存在する特定の文字の個数カウント
int stringcount(string s, char c){ return count(s.cbegin(), s.cend(), c); }

vector<string> split(string str, char del){
	int first = 0;
	int last = str.find_first_of(del);

	vector<string> result;

	while(first < str.size()){
		string subStr(str, first, last - first);

		result.push_back(subStr);
		first = last + 1;
		last = str.find_first_of(del, first);
		if(last == string::npos) last = str.size();
	}
	return result;
}

// Implementation of itoa() 
string itoa(int num, int base){
	int i = 0;
	bool isNegative = false;
	string str;

	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if(num == 0){
		str = "a";
		return str;
	}

	// In standard itoa(), negative numbers are handled only with  
	// base 10. Otherwise numbers are considered unsigned. 
	if(num < 0 && base == 10){
		isNegative = true;
		num = -num;
	}

	// Process individual digits 
	while(num != 0){
		int rem = num % base;
		//str[i++] = (rem > 9)?(rem - 10) + 'a':rem + '0';
		str.push_back(rem + 'a');
		num = num / base;
	}

	// If number is negative, append '-' 
	if(isNegative)
		str.push_back('-');

	//str[i] = '\0'; // Append string terminator 

	// Reverse the string 
	reverse(ALL(str));

	return str;
}

vector<mint> Factorial(int n){
	vector<mint> v(n + 1);
	int ans = 1;
	int index = 1;
	v[0] = 1;
	while(n >= index){
		v[index] = v[index - 1] * index;
		index++;
	}
	//reverse(ALL(v));
	//v[0] = 1;

	return v;
}
//
//int npr( int n , int r ) {
//	return Factorial( n ) / Factorial( n - r );
//}
//
//int ncr( int n , int r ) {
//	return npr( n , r ) / Factorial( r );
//}
#endif
#endif
//--------------------------------8<-------------------------------------

void solve(){
	int n; cin >> n;
	cout << (n >= 30?"Yes":"No");


}


signed main(){
	clock_t start = clock();
	solve();
	auto time1 = clock() - start;
	cout << endl;
	dbg(time1 / (double)CLOCKS_PER_SEC);
	return 0;
}

//fact,dfs,cppint,pow