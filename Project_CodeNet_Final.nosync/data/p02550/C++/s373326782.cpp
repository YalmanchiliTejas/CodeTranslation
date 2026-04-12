#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
//#include <numeric> //iota
//#include <sstream>
//#include <cstring>
//#include <tuple>
//#include <random>
//#include <string>
//#include <unordered_set>
//#include <bitset>
//#include <unordered_map>
//#include <stack>
//#include <cmath>
//#include <deque>
//#include <queue>
//#include <list>
#include <array>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define vec vector
#define pb push_back
#define pp pop_back
#define fi first
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define se second
#define un_map unordered_map
#define rep(i,a,n) for (int i = a; i < n; ++i) 
#define inc_rep(i,a,n,inc) for (int i = a; i < n; i += inc) 
#define couts(x) cout << x << "\n" 
#define watch(x) cout << #x << " : " << x << endl;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<long long, long long>  PLII;
template<typename T>
void print(vector<T>& v) {rep(i, 0, (int)v.size()) cout << v[i] << " ";cout << endl;}
int nxt() {int x;cin >> x;return x;}
ll nxtl() {ll x;cin >> x;return x;}
string nxts() {string x;cin >> x;return x;}
double nxtd() {double x; cin >> x; return x;}
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


ll power_mod(ll a, ll b, ll mo) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans % mo * a % mo) % mo;
		}
		a = (a % mo * a % mo) % mo;
		b /= 2;
	}
	return ans;
}
ll POW(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b /= 2;
	}
	return ans;
}

//string int_to_string(int x) {
    //stringstream ss;
	//ss << x;
	//string ni = ss.str();
	//return ni;
//}


//int string_to_int(string x) {
	//int n;
	//stringstream s(x);
	//s >> n;
	//return n;
//}

//char int_to_char(int a) {
	//return a + '0';
//}
 
 
//void INVERSE() {
    //fact[0] = 1;
    //for (ll i = 1; i <= z; ++i) {
        //fact[i] = (fact[i - 1] * i) % mod;
    //}
    //inv[0] = 1;
    //inv[1] = 1;
    //for (ll i = 2; i <= z; ++i) {
        //inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod; 
    //}
    //mul[0] = 1;
    //for (int i = 1; i <= z; ++i) {
        //mul[i] = (mul[i - 1] * inv[i]) % mod;
    //}
//}
 
//read questions carefully , write clean code and check your logic again on WA !!!

//problems are not difficult just make sure you understand the qusetion and just
//think smartly (make sure to use pen and paper when needed)


//void update(int index, int val) {
	//for (; index <= n; index += index & -index) {
		//fen[index] = (val + fen[index]) % mod;
	//}
//}
//void query(int index) {
	//long long sum = 0;
	//for (; index > 0; index -= index & -index) {
		//sum = (sum + fen[index]) % mod;
	//}
	//return sum;
//}

int main() {
	IOS;
	long long n, x, m;
	cin >> n >> x >> m;
	vector<long long> v(m);
	v[x % m] = 1;
	long long d = x;
	long long cnt = 1;
	vector<long long> values;
	values.push_back(x % m);
	long long ans = x % m;
	vector<ll> index(m);
	index[x % m] = 0;
	ll inn = 0;
	for (int i = 1; i < n; ++i) {
		long long p = (d * d) % m;
		if (v[p]){
			 inn = index[p];
			 break;
		 }
		d = p;
		ans += p;
		values.push_back(p);
		index[p] = i;
		v[p] = 1;
		cnt++;
	}
	ll size = (ll)values.size();
	ll loop = (n - cnt) / (size - inn);
	ll left = (n - cnt) %  (size - inn);
	long long xy = 0;
	for (int i = inn; i < size; ++i) {
		xy = (xy + values[i]);
	}
	ans = (ans + xy * loop);
	for (int i = inn; i < inn + left; ++i) {
		ans += values[i];
	}
	cout << ans;
}


































