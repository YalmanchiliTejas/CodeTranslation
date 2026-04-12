#pragma region _head

#include<iostream>
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

void Init() {
	std::cin.tie(0); std::ios::sync_with_stdio(false);
	struct Init_caller { Init_caller() { Init(); } }caller;
}

#pragma region _define

#define int LL
#define f(i,a,b) for(LL i=a;i<b;i++)
#define rep(i,n) for(LL i=0;i<n;i++)
#define rep2(i,j,a,h,w) for(LL i=0;i<h;i++)for(LL j=0;j<w;j++)cin>>a[i][j]
#define f_vI(v,n) f(i,0,n)cin>>v[i]
#define f_v2I(v1,v2,n) f(i,0,n)cin>>v1[i]>>v2[i]
#define f_v3I(v1,v2,v3,n) f(i,0,n)cin>>v1[i]>>v2[i]>>v3[i]
#define f_vO(v,n) f(i,0,n)cout<<v[i]<<endl
#define ei else if
#define all(a) a.begin(),a.end()
#define size(s) ((LL)s.size())
#define F first
#define S second
#define check() cout<<"! ! !"
#define endl "\n"
#define _y() cout<<"Yes"<<endl
#define _Y() cout<<"YES"<<endl
#define _n() cout<<"No"<<endl
#define _N() cout<<"NO"<<endl
#define INT_INF 1<<29
#define LL_INF 1LL<<60
#define MOD 1000000007

#pragma endregion

#pragma region _using

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
using mll = map<int, int>;
using mcl = map<char, int>;
using vpi = vector<pi>;
using vppi = vector<ppi>;
using qpi = queue<pi>;


#pragma endregion

//十字移動のみ
int cross_x[] = { -1,0,0,1 };
int cross_y[] = { 0,1,-1,0 };

struct edge {
	int f, t, c; // from, to, cost
};

void y_n(bool p) {
	p ? _y() : _n();
}

void Y_N(bool p) {
	p ? _Y() : _N();
}

LL vmax(vi v, LL n) {
	int MAX = 0;
	f(i, 0, n) {
		MAX = max(MAX, v[i]);
	}
	return MAX;
}

LL vmin(vi v, LL n) {
	int MIN = LL_INF;
	f(i, 0, n) {
		MIN = min(MIN, v[i]);
	}
	return MIN;
}

LL gcd(LL a, LL b) {
	if (b == 0) {
		swap(a, b);
	}
	LL r;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}
LL lcm(LL a, LL b) {
	return (a / gcd(a, b) * b);
}

//素数判定
bool is_prime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


//素因数分解
void dec_prime(int n) {
	int a = 2;
	while (a*a <= n) {
		if (n % a == 0) {
			cout << a << endl;
			n /= a;
		}
		else {
			a++;
		}
	}
	cout << n << endl;
}

//エラトステネスの篩
void sieve_prime(LL n) {
	vb s(n + 1, true);
	f(i, 2, n + 1) {
		for (int j = 2; i*j <= n; j++) {
			s[i*j] = false;
		}
	}
	cout << "2から" << n << "までの素数" << endl;
	f(i, 2, n + 1) {
		if (s[i]) {
			cout << i << " ";
		}
	}
}

//階乗計算
LL factorial(LL n) {
	LL a = 1, ret = 1;
	while (a < n) {
		a++;
		ret *= a;
		ret %= MOD;
	}
	return ret;
}


#pragma endregion 

/*****************************************************************************/
signed main() {
	int n, m;
	cin >> n >> m;
	vvb g(n, vb(n, false));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = g[b][a] = true;
	}
	vi num(n);
	rep(i, n) {
		num[i] = i;
	}
	int ans = 0;
	while (num[0] == 0) {
		bool f = true;
		rep(i, n - 1) {
			if (g[num[i]][num[i + 1]] == false) {
				next_permutation(all(num));
				f = false;
				break;
			}
		}
		if (f) {
			ans++;
			next_permutation(all(num));
		}
	}
	cout << ans;
	return 0;
}