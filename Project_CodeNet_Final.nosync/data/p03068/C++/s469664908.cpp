#include<bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
#define double long double
#define vec vector
#define pb push_back
#define unset unordered_set
#define ii pair<int, int>
#define X first
#define Y second
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define bitcount(n) __builtin_popcountll(n)
typedef vector<int> vi;
template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {
  return {l.first+r.first,l.second+r.second};
} 
typedef void (*callback_function)(void); // type for conciseness
const long long ZERO = 0LL;
const long long INF64 = 1e18;
const int INF32 = 1e9;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0L);
const double EPS = static_cast<double>(1e-9);
#define min(a, b) (((a)<(b))?(a):(b))
#define max(a, b) (((a)>(b))?(a):(b))

ll powMod(ll a, ll m) { // a^m % MOD
	a %= MOD;
	long long res = 1;
	while (m > 0) {
		if (m & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		m >>= 1;
	}
	return res;
}

const int maxV = 10; // we need inv(3) only
ll inv[maxV];
ll inverse(int q) { // q<maxV; WORKs only with MOD prime!
	inv[1] = 1LL;
	for(int i = 2; i < maxV; ++i)
	    inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
	return inv[q];
}




//#undef int
int main() {
//#define int long long
	ios_base::sync_with_stdio(false); cin.tie();
	//auto beginProgram = chrono::steady_clock::now();
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int n; cin >> n;
	string s; cin >> s;
	int k; cin >> k;
	for(int i=0; i<(int)s.length(); ++i) 
		if(s[i] != s[k-1])
			s[i] = '*';
	cout << s << endl;
	
  //auto endProgram = chrono::steady_clock::now();
  return 0;
}
