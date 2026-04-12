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

#pragma region _define

#define int LL
#define f(i,a,b) for(LL i=a;i<b;i++)
#define rep(i,n) for(LL i=0;i<n;i++)
#define f_vI(v,n) f(i,0,n)cin>>v[i]
#define f_v2I(v1,v2,n) f(i,0,n)cin>>v1[i]>>v2[i]
#define f_v3I(v1,v2,v3,n) f(i,0,n)cin>>v1[i]>>v2[i]>>v3[i]
#define f_vO(v,n,option) f(i,0,n)cout<<v[i]<<option;
#define all(a) a.begin(),a.end()
#define size(s) ((int)s.size())
#define check() cout<<"! ! !"
#define endl "\n"
#define _y() cout<<"Yes"<<endl
#define _Y() cout<<"YES"<<endl
#define _n() cout<<"No"<<endl
#define _N() cout<<"NO"<<endl
#define INT_INF 1<<29
#define LL_INF 1LL<<60
#define MOD 10000007

#pragma endregion

#pragma region _using

using namespace std;

using LL = long long;
using st = string;
using vi = vector<LL>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vc = vector<char>;
using vs = vector<st>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using qi = queue<int>;
using qc = queue<char>;
using qs = queue<st>;
using si = stack<LL>;
using sc = stack<char>;
using ss = stack<st>;
using pi = pair<LL, LL>;
using mll = map<LL, LL>;
using vpi = vector<pi>;

#pragma endregion


//素数判定
bool is_prime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

void y_n(bool p) {
	if (p)_y();
	else _n();
}

void Y_N(bool p) {
	if (p) _Y();
	else _N();
}

LL gcd(LL a, LL b) {
	LL r;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}
LL lcm(LL a, LL b) {
	return (a / gcd(a, b)*b);
}

//階乗計算
LL factorial(LL n) {
	LL a = 1, ret = 1;
	while (a < n) {
		a++;
		ret *= a;
		//ret %= 1000000007;
	}
	return ret;
}

#pragma endregion


/************************************************************************/
signed main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	while (1) {
		st s;
		cin >> s;
		if (s == "#")break;
		bool f;
		int ans = 0;
		rep(i, size(s)) {
			if (i == 0) {
				if (s[0] == 't' || s[0] == 'g' || s[0] == 'b' || s[0] == 'r' || s[0] == 'f' || s[0] == 'v' || s[0] == 'e' || s[0] == 'd' || s[0] == 'c' || s[0] == 'w' || s[0] == 's' || s[0] == 'x' || s[0] == 'q' || s[0] == 'a' || s[0] == 'z') {
					f = true;
				}
				else {
					f = false;
				}
			}
			else {
				if (f == false && (s[i] == 't' || s[i] == 'g' || s[i] == 'b' || s[i] == 'r' || s[i] == 'f' || s[i] == 'v' || s[i] == 'e' || s[i] == 'd' || s[i] == 'c' || s[i] == 'w' || s[i] == 's' || s[i] == 'x' || s[i] == 'q' || s[i] == 'a' || s[i] == 'z')) {
					ans++;
					f = true;
				}
				else if (f == true && (s[i] == 'y' || s[i] == 'h' || s[i] == 'n' || s[i] == 'u' || s[i] == 'j' || s[i] == 'm' || s[i] == 'i' || s[i] == 'k' || s[i] == 'm' || s[i] == 'o' || s[i] == 'l' || s[i] == 'p')) {
					ans++;
					f = false;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
