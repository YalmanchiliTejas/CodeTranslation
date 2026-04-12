#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include <iomanip> 
#include <stack> 
#include <cmath> 

#define maxn 400010
#define LL long long
#define inf 10000000000
#define mod 1000000007
#define pi 3.14159265359
using namespace std;
int dx[24] = { 1,0,-1,0 ,2,0,-2,0 ,-1,-1,-2,-2 ,1,1,2,2    ,-1,-1,-2,-2 ,1,1,2,2 };
int dy[24] = { 0,1,0,-1 ,0,2,0,-2 ,-1,-2,-1,-2 ,-1,-2,-1,-2,1,2,1,2     ,1,2,1,2  };


LL n, m, k;
LL arr[maxn];
LL arr2[maxn];
//int visit[maxn];
//int cache[maxn];
//int c[maxn];
//int g[maxn];
//int dfsnum = 0;
//vector<vector<int>>rvi;
//vector<vector<int>>scc;
//vector<pair<int, int>>ett;
//stack<int>st;
//bool flg = 1;
//LL s, d;
//
//int findp(int a) {
//	if (c[a] <0)return a;
//	return c[a] = findp(c[a]);
//}
//void unionp(int a, int b) {
//	a = findp(a);
//	b = findp(b);
//
//	if (a != b) {
//		c[a] += c[b];
//		c[b] = a;
//	}
//
//}
//LL power(LL x, LL y) {
//	LL ret = 1;
//	while (y > 0) {
//		if (y % 2) {
//			ret *= x;
//			ret %= mod;
//		}
//		x *= x;
//		x %= mod;
//		y /= 2;
//	}
//	return ret;
//}
//void dfs2(int v) {
//	cache[v] = 1;
//	scc.back().push_back(v);
//	for (int nv : rvi[v]) {
//		if (cache[nv])continue;
//		dfs2(nv);
//	}
//
//}
//LL fac(LL n) {
//	if (n == 1) return 1;        
//	return (n * fac(n - 1) - power(2,n-1) )%mod;
//}
//int fac2(LL n) {
//	LL res, i;
//	if (n == 1)return n;
//	res = n;
//	for (int i = n - 1; i > 0; --i) {
//		res *= i;
//		res %= mod;
//	}
//	return res;
//}

LL gcd(LL a, LL b) {
	while (b != 0) {
		LL r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//int t;   cin >> t; cin.ignore();
	int t = 1;
	for (int test_case = 0; test_case < t; ++test_case) {
		int flg = 0;
		LL ans1 = 0, ans2 = 0;
		string ans[2] = { "No","Yes" };
		string s1, s2 = "";
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		arr2[0] = arr[0];
		for (int i = 1; i < n; ++i) {
			arr2[i] = (arr[i] + arr2[i - 1])%mod;
		}
		for (int i = 0; i < n; ++i) {
			ans1 = (ans1%mod+((arr2[n-1] - arr2[i])*arr[i])%mod)%mod;
			if (ans1 < 0)ans1 += mod;
		}
		cout << ans1%mod;
		cout << '\n';

	}
	return 0;
}
