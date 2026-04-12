#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20);
#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define sortv(v) sort(all(v))
#define sortg(v) sort(all(v), greater<int>())
#define countv(v, c) count(all(v), c)
#define gcd __gcd
#define rep(i, m, n) for(int i=(int)(m);i<(int)(n);i++)
#define _rep(i, n) rep(i, 0, n)
#define rev(i, m, n) for(int i=(int)(m-1);i>=(int)(n);i--)
#define _rev(i, n) rev(i, n, 0)
#define each(i, n) for(auto&& i: n)
void in(){}
template<typename F, typename... R>
bool in(F& f, R&... r){
	if(cin >> f){in(r...);return true;}
	else{return false;}
}
#define inv(x) each(i, x) in(i)
#define out(x) cout << (x)
#define space() cout << " "
#define indent() cout << '\n'
void print(){}
template<typename F, typename... R>
void print(F f, R... r){out(f), indent(), print(r...);}
#define printv(x) each(i, x) out(i), space(); indent()
#define debughead(x) cerr << "Line " << __LINE__ << ": " << #x << ": "
#define debugout(x) cerr << (x) << " "
#define debugindent() cerr << '\n'
#define debug(x) debughead(x), debugout(x), debugindent()
#define YN(x) out((x) ? "YES" : "NO"), indent()
#define Yn(x) out((x) ? "Yes" : "No"), indent()
#define yn(x) out((x) ? "yes" : "no"), indent()
const int INF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-15;
const double PI = acos(-1);
const int dx[] = {0, 0, 1, 0, -1, -1, 1, 1, -1};
const int dy[] = {0, -1, 0, 1, 0, -1, -1, 1, 1};
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
int lcm(int a, int b){return a / gcd(a, b) * b;}
int factorial(int a){return a < 2 ? 1 : factorial(a - 1) * a;}
int summation(int a){return a < 1 ? 0 : (a * a + a) / 2;}
int combination(int n, int r){
	int res = 1;
	rep(i, 1, r + 1){
		res *= n--, res /= i;
	}
	return res;
}
bool isPrime(int n){
	rep(i, 2, sqrt(n) + 1){
		if(i > 3){
			i++;
		}
		if(!(n % i)){
			return false;
		}
	}
	return true;
}
vector<int> divisor(int n){
	vector<int> ans;
	rep(i, 1, sqrt(n) + 1){
		if(!(n % i)){
			ans.pb(i);
			if(i * i < n){
				ans.pb(n / i);
			}
		}
	}
	return ans;
}
map<int, int> factorization(int n){
	map<int, int> ans;
	rep(i, 2, sqrt(n) + 1){
		if(i > 3){
			i++;
		}
		while(!(n%i)){
			ans[i]++, n /= i;
		}
	}
	if(n > 1){
		ans[n]++;
	}
	return ans;
}
int n, tmp, res = 0;
string s;
main(){INCANT;
	/*-------------------*/
	
	in(s);
	Yn(!(s=="AAA"||s=="BBB"));
	
	/*-------------------*/
}