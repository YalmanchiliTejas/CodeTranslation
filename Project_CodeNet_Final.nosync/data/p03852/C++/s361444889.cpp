			
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream> 

using namespace std;

inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

template<class T> inline T sqr(T x) { return x*x; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define P(p) cout<<(p)<<endl;
#define VEC_2D(a,b) vector<vector<int> >(a, vector<int>(b, 0))
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define INF (1100000000)
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MOD 1000000007LL
#define FSP(a) cout << fixed << setprecision(a)


ll gcd(ll x, ll y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return n != 1;
}
map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}
int extgcd(int a, int b, int& x, int& y) {//
	int d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}



ll mod_pow(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	return res;
}
vector<string> split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while ((found = str.find_first_of(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

bool is_kadomatsu(int a, int b, int c) {
	if (a == b || a == c || b == c)return false;
	if (a > b && c > b) return true;
	if (a < b && c < b)return true;
	return false;
}


struct UF {
	int n;
	vi d;
	UF() {}
	UF(int n) :n(n), d(n, -1) {}
	int root(int v) {
		if (d[v] < 0) return v;
		return d[v] = root(d[v]);
	}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (size(x) < size(y)) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	int size(int v) { return -d[root(v)]; }
};



vector<int> divisor(int n) {
	if (n == 1) return{};
	vi res;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.emplace_back(i);
			if (i != 1 && i != n / i)res.emplace_back(n / i);
		}
	}
	return res;
}
//-------------------------------------------------------------


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	string s;
	cin >> s;
	if (s == "a" || s == "i" || s == "u" || s == "e" || s == "o") {
		P("vowel");
	}
	else {
		P("consonant");
	}
	return 0;
		//ifstream ifs("soc-LiveJournal1.txt"); //グラフの読み込み
		//ofstream output("soc-LiveJournal2.txt");
		//int u, v;
		//string s;
		//bool is_0_start = false;
		//int count = 0;
		//rep(i, 4) getline(ifs, s);
		//for (; ifs >> u >> v;) {
		//	if (u == 0) is_0_start = true;
		//	if (!is_0_start) {
		//		u--;
		//		v--;
		//	}
		//	count++;
		//	if(count%10000==0)cout << count << endl;
		//	output << u << " " << v << endl;
		//}
}

	
