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

#pragma region _define

#define int LL
#define f(i,a,b) for(LL i=a;i<b;i++)
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
#define INF 1<<29
#define MOD 1000000007

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
using qi = queue<LL>;
using qc = queue<char>;
using qs = queue<st>;
using si = stack<LL>;
using sc = stack<char>;
using ss = stack<st>;
using pi = pair<LL, LL>;
using vpi = vector<pi>;

#pragma endregion

#pragma region _graph

#define node 50  //グラフの最大位数　適宜変更
//bool graph[node][node]; bool visited[node] = { false };
#define link(a,b,m) f(i,0,m){cin>>a[i]>>b[i]; a[i]--; b[i]--; graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;}

#pragma endregion

LL gcd(LL a, LL b) {
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
signed main(void) {
	cin.tie(0); ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vi a(n);
	f_vI(a, n);
	qi ans1;
	si ans2;
	bool f = true;
	for (int i = n - 1; i >= 0;i--) {
		if (f) {
			ans1.push(a[i]);
			f = false;
		}
		else {
			ans2.push(a[i]);
			f = true;
		}
	}
	while (!ans1.empty()) {
		cout << ans1.front() << " ";
		ans1.pop();
	}
	while (!ans2.empty()) {
		cout << ans2.top() << " ";
		ans2.pop();
	}
	return 0;
}