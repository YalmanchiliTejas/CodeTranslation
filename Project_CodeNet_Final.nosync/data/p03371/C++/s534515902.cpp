#include<iostream>
#include<fstream>
#include<bitset>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
#include<queue>
#include<stack>
#include<numeric>
#include<utility>
#include<regex>
#include<climits>

void Init() {
	std::cin.tie(0); std::ios::sync_with_stdio(false);
	struct Init_caller { Init_caller() { Init(); } }caller;
}


#define int LL
#define rep(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define all(a) (a).begin(),(a).end()
#define check() cout<<"! ! !"<<endl
#define endl "\n"
#define _y() cout<<"Yes"<<endl
#define _Y() cout<<"YES"<<endl
#define _n() cout<<"No"<<endl
#define _N() cout<<"NO"<<endl
#define INT_INF INT_MAX
#define INF LLONG_MAX
#define MOD (1000000000+7)



using namespace std;


using LL = long long;
using st = string;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<st>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using qi = queue<int>;
using qc = queue<char>;
using qs = queue<st>;
using si = stack<int>;
using sc = stack<char>;
using ss = stack<st>;
using pi = pair<int, int>;
using ppi = pair<pi, int>;
using mii = map<int, int>;
using mpii = map<pi, int>;
using mib = map<int, bool>;
using mci = map<char, int>;
using msb = map<st, bool>;
using vpi = vector<pi>;
using vppi = vector<ppi>;
using spi = stack<pi>;
using qpi = queue<pi>;



//4,2,8,6,1,7,3,9,5
int dx[] = { -1,0,0,1,-1,-1,1,1,0 };
int dy[] = { 0,1,-1,0,1,-1,1,-1,0 };

template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
	rep(i, v.size()) {
		in >> v[i];
	}

	return in;
}

template<typename T, typename U>
istream &operator>>(istream&in, vector<pair<T, U>> &p) {
	rep(i, p.size()) {
		in >> p[i].first >> p[i].second;
	}

	return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
	out << "{";
	rep(i, v.size()) {
		out << v[i] << ",";
	}
	out << "}" << endl;

	return out;
}

template<typename T, typename U>
ostream &operator<<(ostream&out, vector<pair<T, U>> &p) {
	rep(i, p.size()) {
		out << "{" << p[i].first << "," << p[i].second << "}" << endl;
	}

	return out;
}

struct mint {
	int x;
	mint(int x = 0) :x((x%MOD + MOD) % MOD) {}

	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
	mint pow(int t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	mint inv() const {
		return pow(MOD - 2);
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const {
		mint res(*this);
		return res /= a;
	}
};

void y_n(bool p) {
	p ? _y() : _n();
}

void Y_N(bool p) {
	p ? _Y() : _N();
}

//MAX,maxpos,MIN,minpos
template<typename T>
pair<pair<T, int>, pair<T, int>> vmaxmin(vector<T> v) {
	int n = v.size();
	int MAX = -INF;
	int MIN = INF;
	int maxpos = 0;
	int minpos = 0;
	rep(i, n) {
		if (MAX < v[i]) {
			maxpos = i;
			MAX = v[i];
		}
		if (MIN > v[i]) {
			minpos = i;
			MIN = v[i];
		}
	}
	return { {MAX,maxpos},{MIN,minpos} };
}

template<typename T>
T vsum(vector<T> v) {
	int n = v.size();
	T sum = 0;
	rep(i, n) {
		sum += v[i];
	}
	return sum;
}

int gcd(int a, int b) {
	if (b == 0) {
		swap(a, b);
	}
	int r;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}
int lcm(int a, int b) {
	return (a / gcd(a, b) * b);
}

bool is_square(int n) {
	if ((int)sqrt(n)*(int)sqrt(n) == n) {
		return true;
	}
	else {
		return false;
	}
}


bool is_prime(int n) {
	if (n <= 1) {
		return true;
	}
	else {
		for (int i = 2; i*i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
	}
	return true;
}

void dec_num(int n, vi &v) {
	int a = 2;
	v.push_back(1);
	v.push_back(n);
	while (a*a <= n) {
		if (n%a == 0) {
			v.push_back(a);
			v.push_back(n / a);

		}
		a++;
	}
	sort(all(v));
}


void dec_prime(int n, vi &v) {
	//v.push_back(1);
	int a = 2;
	while (a*a <= n) {
		if (n % a == 0) {
			v.push_back(a);
			n /= a;
		}
		else {
			a++;
		}
	}
	v.push_back(n);
}

//nの素因数分解の指数表示
void dec_prime_e(int n, map<int, int> &m) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			int e = 0;
			while (n%i == 0) {
				e++;
				n /= i;
			}
			m[i] += e;
		}
	}
	if (n != 1) m[n]++;
}
//指数部のみの列挙
/*for (auto j : m) {
		p.push_back(j.second);
	}
*/


int sieve_prime(int a, int b) {
	if (a > b)swap(a, b);
	vb s(b + 1, true);
	int cnt_a = 0, cnt_b = 0;
	for (int i = 2; i <= b; i++) {
		for (int j = 2; i*j <= b; j++) {
			s[i*j] = false;
		}
	}
	for (int i = 2; i <= b; i++) {
		if (s[i]) {
			//cout << i << " ";
			if (i < a) {
				cnt_a++;
			}
			cnt_b++;
		}
	}
	return cnt_b - cnt_a;
}


int factorial(int n) {
	int a = 1, ret = 1;
	while (a < n) {
		a++;
		ret *= a;
		//ret %= MOD;
	}
	return ret;
}


int bit_count(int n) {
	int k = (int)log2(n) + 1;
	int ret = 0;
	rep(i, k) {
		if (n&(1LL << i))ret++;
	}
	return ret;
}


const int COMBMAX = 4000;
int comb[COMBMAX + 5][COMBMAX + 5];

void init_comb() {
	comb[0][0] = 1;
	rep(i, COMBMAX) {
		rep(j, i + 1) {
			comb[i + 1][j] += comb[i][j];
			comb[i + 1][j] %= MOD;
			comb[i + 1][j + 1] += comb[i][j];
			comb[i + 1][j + 1] %= MOD;
		}
	}
}

int combination(int n, int k) {
	if (k<0 || k>n)return 0;
	else return comb[n][k];
}


const int COMBMODMAX = 5000000;
int fac[COMBMODMAX + 5], facinv[COMBMODMAX + 5], inv[COMBMODMAX + 5];

void init_comb_mod() {
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < COMBMODMAX; i++) {
		fac[i] = fac[i - 1] * i%MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		facinv[i] = facinv[i - 1] * inv[i] % MOD;
	}
}

//nCk (mod p)
int comb_mod(int n, int k) {
	if (n < k)return 0;
	if (n < 0 || k < 0)return 0;
	return fac[n] * (facinv[k] * facinv[n - k] % MOD) % MOD;
}

//x^n (mod p)
int pow_mod(int x, int n, int p) {
	if (n == 0)return 1;
	int res = pow_mod(x*x%p, n / 2, p);
	if (n % 2 == 1)res = res * x % p;
	return res;
}


struct edge {
	int to;
	int cost;
};


using ve = vector<edge>;
using vve = vector<ve>;


/*****************************************************************************/

signed main() {
	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = INT_INF;
	rep(C, 1000000) {
		int A = C / 2, B = C / 2;
		ans = min(ans, c*C + a * max(0ll, x - A) + b * max(0ll, y - B));
	}
	cout << ans;



}