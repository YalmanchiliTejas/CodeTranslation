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
#define size(s) ((LL)s.size())
#define F first
#define S second
#define check() cout<<"! ! !"
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
	rep(i, size(v)) {
		in >> v[i];
	}

	return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
	out << "{";
	rep(i, size(v)) {
		out << v[i] << ",";
	}
	out << "}" << endl;
	return out;
}

void y_n(bool p) {
	p ? _y() : _n();
}

void Y_N(bool p) {
	p ? _Y() : _N();
}

pi vmax(vi v) {
	int n = size(v);
	int MAX = 0;
	int pos = 0;
	rep(i, n) {
		if (MAX < v[i])pos = i;
		MAX = max(MAX, v[i]);
	}
	return { MAX,pos };
}

pi vmin(vi v) {
	int n = size(v);
	int MIN = INF;
	int pos = 0;
	rep(i, n) {
		if (MIN > v[i])pos = i;
		MIN = min(MIN, v[i]);
	}
	return { MIN,pos };
}

int vsum(vi v) {
	int n = size(v);
	int sum = 0;
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
	if (n == 1) {
		return false;
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
	if (n != 1)m[n]++;
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
	int k = log2(n) + 1;
	int ret = 0;
	rep(i, k) {
		if (n&(1 << i))ret++;
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

class UF {
public:

	vi par;
	vi rank;

	UF(int n) {
		par.resize(n, -1);
		rank.resize(n, 0);
	}

	int root(int x) {
		if (par[x] == -1)return x;
		return par[x] = root(par[x]);
	}

	//xの集合の位数
	int order(int x) {
		return -par[root(x)];
	}

	//xとyを併合
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return;
		}

		if (rank[x] < rank[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rank[x] == rank[y])rank[x]++;
		}
	}

	//xとyが同じ集合にあるか
	bool is_same(int x, int y) {
		return root(x) == root(y);
	}
};

class SegmentTree {
private:
	int n;
	vi node;
	int size;
	int init; //クエリによって決定

public:

	//SegmentTree s(vi(n,INF))とか書く
	SegmentTree(vi v) {
		this->size = size(v);

		n = 1;
		init = v[0];
		while (n < size)n *= 2;
		node.resize(2 * n - 1, init);

		rep(i, size) {
			node[i + n - 1] = v[i];
		}

		for (int i = n - 2; i >= 0; i--) {
			node[i] = min(node[2 * i + 1], node[2 * i + 2]);
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	//																								  //
	// 以下の関数はあくまで更新クエリと区間内最小値クエリのものであって、問題によって変える必要がある //
	//																								  //
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//node[x]の値をvalに更新
	void update(int x, int val) {
		x += (n - 1);

		node[x] = val;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = min(node[2 * x + 1], node[2 * x + 2]); //右辺はクエリによって定義
		}
	}

	//区間[a,b)内の最小値を返す
	///b未満だから！
	int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		if (r <= a || b <= l)return init;
		if (a <= l && r <= b)return node[k];

		int L = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
		int R = getmin(a, b, 2 * k + 2, (l + r) / 2, r);

		return min(L, R); //右辺はクエリによって定義
	}
};

struct edge {
	int to;
	int cost;
};


using ve = vector<edge>;
using vve = vector<ve>;


/*****************************************************************************/
int rec(int n, int x, vi &a, vi &p) {
	if (n == 0) {
		if (x > 0)return 1;
		else return 0;
	}
	if (x == 1) {
		return 0;
	}
	else if (x <= 1 + a[n - 1]) {
		return rec(n - 1, x - 1, a, p);
	}
	else if (x == 2 + a[n - 1]) {
		return p[n - 1] + 1;
	}
	else if (x < a[n]) {
		return p[n - 1] + 1 + rec(n - 1, x - a[n - 1] - 2, a, p);
	}
	else if(x==a[n]){
		return p[n];
	}
	else {
		return 0;
	}
}
signed main() {

	int n, x;
	cin >> n >> x;
	vi a(n + 1), p(n + 1);
	a[0] = 1; p[0] = 1;
	rep(i, n) {
		a[i + 1] = 2 * a[i] + 3;
		p[i + 1] = 2 * p[i] + 1;
	}
	cout << rec(n, x, a, p);
}