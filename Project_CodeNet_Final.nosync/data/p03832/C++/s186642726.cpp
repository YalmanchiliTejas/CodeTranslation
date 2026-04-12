#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define ALL(obj) (obj).begin(),(obj).end()

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template<class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl;exit(0);}else return;}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
void YN(bool flg) {cout << ((flg) ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << ((flg) ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << ((flg) ? "yes" : "no") << endl;}

//Repeat Square Method x^n MOD 
long long RSM(long long x, long long n, long long MOD) {
	long long y = 1;
	for (; n > 0; n >>= 1, (x *= x) %= MOD) if (n & 1) (y *= x) %= MOD;
	return y;
}

vector<long long> Factorial(long long N, long long mod){
	vector<long long> res(N + 1, 1);
	for (long long i = 1; i <= N; ++i) res[i] = (res[i - 1] * i)%mod;
	return res;
}

vector<vector<long long>> Permutation(long long N, long long mod) {
	vector<long long> fac(N + 1, 1);
	for (long long i = 1; i <= N; ++i) fac[i] = (fac[i - 1] * i) % mod;
	vector<long long> inv(N + 1, 1);
	for (long long i = 1; i <= N; ++i) inv[i] = RSM(fac[i],mod-2,mod);
	vector<vector<long long>> res(N + 1, vector<long long>(N + 1, 1));
	for (long long i = 1; i <= N; ++i) for (long long j = 1; j <= i; ++j) res[i][j] = (fac[i] * inv[i - j]) % mod;
	return res;
}



int main() {
	ll N,A,B,C,D; cin >> N >> A >> B >> C >> D;

	auto fac = Factorial(N, MOD);
	auto per = Permutation(N, MOD);
	auto inv = fac;
	REP(i, N + 1) inv[i] = RSM(inv[i], MOD - 2, MOD);
	V<V<ll>> dp(N+1, V<ll>(N+1, 0));
	dp[A - 1][0] = 1;
	for(ll i = A; i <= B; ++i){
		for(ll j = 0; j <= N; ++j){
			(dp[i][j] += dp[i - 1][j]) %= MOD;
			for(ll k = C; k <= D && j - k*i >= 0; ++k){
				dp[i][j] += dp[i - 1][j - k*i]%MOD*per[N-(j-k*i)][k*i]%MOD*inv[k]%MOD*RSM(inv[i],k,MOD)%MOD;
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[B][N] << endl;
	return 0;
}

