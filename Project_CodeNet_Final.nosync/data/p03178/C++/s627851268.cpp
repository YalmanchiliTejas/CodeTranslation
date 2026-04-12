/*
	$$$$$$$\                      $$\           $$$$$$$\
	$$  __$$\                     \__|          $$  __$$\
	$$ |  $$ | $$$$$$\   $$$$$$\  $$\  $$$$$$$\ $$ |  $$ | $$$$$$\   $$$$$$\   $$$$$$$\ $$$$$$\
	$$$$$$$\ |$$  __$$\ $$  __$$\ $$ |$$  _____|$$$$$$$\ | \____$$\ $$  __$$\ $$  _____|\____$$\
	$$  __$$\ $$ /  $$ |$$ |  \__|$$ |\$$$$$$\  $$  __$$\  $$$$$$$ |$$ |  \__|$$ /      $$$$$$$ |
	$$ |  $$ |$$ |  $$ |$$ |      $$ | \____$$\ $$ |  $$ |$$  __$$ |$$ |      $$ |     $$  __$$ |
	$$$$$$$  |\$$$$$$  |$$ |      $$ |$$$$$$$  |$$$$$$$  |\$$$$$$$ |$$ |      \$$$$$$$\\$$$$$$$ |
	\_______/  \______/ \__|      \__|\_______/ \_______/  \_______|\__|       \_______|\_______|
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define MP make_pair
#define INS insert
#define LB lower_bound
#define UB upper_bound
#define pii pair <int,int>
#define pll pair <long long, long long>
#define si pair<string, int>
#define is pair<int, string>
#define X first
#define Y second
#define _ << " " <<
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for (int i = (a); i > (b); --i)
#define FORR(i, l, r) for (int i = (l); i <= (r); ++i)
#define FORP(i, a, b) for ((i) = (a); (i) < (b); ++i)
#define FORA(i, x) for (auto &i : x)
#define REP(i, n) FOR(i, 0, n)
#define BITS(x) __builtin_popcount(x)
#define MSET memset
#define MCPY memcpy
#define SQ(a) (a) * (a)
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <pii> vpi;
typedef vector <ll> vll;
typedef vector <pll> vpl;
typedef vector <double> vd;
typedef vector <ld> vld;
typedef vector<si> vsi;
typedef vector<is> vis;
typedef vector<string> vs;
typedef vector <vi> mat;
//((float) t)/CLOCKS_PER_SEC
 
const int MOD = 1e9 + 7;
const int PI = acos(-1);
const int LOG = 20;
const int INF = 1e9 + 10;
const ll INFL = 1e18 + 10;
const int ABC = 30;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int dox[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int doy[] = {0, 0, -1, 1, -1, 1, -1, 1};
 
inline int sum(int a, int b){
  if (a + b >= MOD)
  	return a + b - MOD;
  if (a + b < 0)
  	return a + b + MOD;
  return a + b;
}
 
inline void add(int &a, int b){
  a = sum(a, b);
}
 
inline int pot(ll pot, int n){
	ll ret = 1;
	while (n){
		if (n & 1)
			ret = (ret * pot) % MOD;
		pot = (pot * pot) % MOD;
		n >>= 1;
	}
	return ret;
}
 
inline int mul(int a, int b){
  return (ll)a * (ll)b % MOD;
}
 
inline int sub(int a, int b){
	return (a - b + MOD) % MOD;
}
 
inline int divide(int a, int b){
	return mul(a, pot(b, MOD - 2));
}
 
ll lcm(ll a, ll b){
	return abs(a * b) / __gcd(a, b);
}
 
inline double ccw(pii A, pii B, pii C){
	return (A.X * B.Y) - (A.Y * B.X) + (B.X * C.Y) - (B.Y * C.X) + (C.X * A.Y) - (C.Y * A.X);
}
 
inline int CCW(pii A, pii B, pii C){
	double val = ccw(A, B, C);
	double eps = max(max(abs(A.X), abs(A.Y)), max(max(abs(B.X), abs(B.Y)), max(abs(C.X), abs(C.Y)))) / 1e9;
	if (val <= -eps)
		return -1;
	if (val >= eps)
		return 1;
	return 0;
}
 
void to_upper(string &x){
	REP(i, sz(x))
		x[i] = toupper(x[i]);
}
 
void to_lower(string &x){
	REP(i, sz(x))
		x[i] = tolower(x[i]);
}
 
string its(ll x){
	if (x == 0)
		return "0";
	string ret = "";
	while (x > 0){
		ret += (x % 10) + '0';
		x /= 10;
	}
	reverse(all(ret));
	return ret;
}
 
ll sti(string s){
	ll ret = 0;
	REP(i, sz(s)){
		ret *= 10;
		ret += (s[i] - '0');
	}
	return ret;	
}
 
const int N = 1e4 + 10;
const int D = 101;
const int OFF = (1 << LOG); 

int memo[2][D][N], d;
string s;

int dp(int f, int ost, int x){
	//cout << l _ c _ f _ ost _ x << '\n';
	if (x == sz(s))
		return (ost == 0);
	int &ret = memo[f][ost][x];
	if (~ret)
		return ret;
	ret = 0;
	if (f == 0){
		REP(i, 10){
			if (i == 0){
				add(ret, dp(0, ost, x + 1));
			} else{
				//cout << curr << '\n';
				add(ret, dp(0, (ost + i) % d, x + 1));
			}
		}
	} else {
			REP(i, s[x] - '0' + 1){
				int f1 = f;
				if (i < s[x] - '0')
					f1 = 0;
				add(ret, dp(f1, (ost + i) % d, x + 1));
			}
		}
	return ret;			
}

int main ()	{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s >> d;
	MSET(memo, -1, sizeof memo);
	dp(1, 0, 0);
	memo[1][0][0] = sub(memo[1][0][0], 1);
	cout << memo[1][0][0] << '\n';
	
	return 0;
} 