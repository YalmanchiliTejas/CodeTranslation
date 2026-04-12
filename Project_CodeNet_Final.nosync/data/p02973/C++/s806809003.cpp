#include "bits/stdc++.h"


using namespace std;
#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,s,n) for(int i=(s);i<(n);++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define REPR(i,s,n) for(int i=(s);i>=(n);--(i))
#define all(a) (a).begin(),(a).end()
#define reall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
#define DOUBLE fixed << setprecision(10)
#define fi first
#define se second
const double pi = acos(-1.0);
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef deque<ll> dll;
typedef pair<ll, ll> P;
typedef vector<P> vP;
const ll mod = 1e9 + 7;
ll dx[4] = { 1,0,-1,0 };
ll dy[4] = { 0,1,0,-1 };
template <typename T>
bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
};
template <typename T>
bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
};
void Pvll(vll v) {
	cout << "------------------------------------------------\n";
	rep(i, v.size()) cout << v[i] << " ";
	cout << endl;
	cout << "------------------------------------------------\n";
}
void Pvvll(vvll v) {
	cout << "------------------------------------------------\n";
	rep(i, v.size()) {
		rep(j, v[i].size()) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------\n";
}

void Ps(string s) {
	cout << "------------------------------------------------\n";
	rep(i, s.size()) cout << s[i] << " ";
	cout << endl;
	cout << "------------------------------------------------\n";
}

void Pvs(vs s) {
	cout << "------------------------------------------------\n";
	rep(i, s.size()) {
		rep(j, s[i].size()) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------\n";
}

void Yes(bool x) {
	if (x) cout << "Yes\n";
	else cout << "No\n";
}

void YES(bool x) {
	if (x) cout << "YES\n";
	else cout << "NO\n";
}

void yes(bool x) {
	if (x) cout << "yes\n";
	else cout << "no\n";
}

void Yay(bool x) {
	if (x) cout << "Yay!\n";
	else cout << ":(\n";
}

ll gcd(ll m, ll n)
{
	// 引数に０がある場合は０を返す
	if ((0 == m) || (0 == n))
		return 0;

	// ユークリッドの方法
	while (m != n)
	{
		if (m > n) m = m - n;
		else         n = n - m;
	}
	return m;
}//gcd

ll lcm(ll m, ll n)
{
	// 引数に０がある場合は０を返す
	if ((0 == m) || (0 == n))
		return 0;

	return (((m*n) / gcd(m, n))); // lcm = m * n / gcd(m,n)
}//lcm

ll  n, m, r, l, k, h, ans = 0, ret = M;
bool flag = false, flag2 = false, flag3 = false;
string s,t;

void INIT() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << DOUBLE;
}

// 最長増加部分列問題(LIS: Longest Increasing Subsequence)
/*
長さnの数列a0,a1,…,an-1がある。
この数列の増加部分列うち、最長のものの長さを求めよ。
ただし、増加部分列とは、全てのi<jでai<ajを満たす部分列のことを言う。

(例)
(入力)
6
1 3 5 2 4 6
(最長部分文字列)
---------
1 2 4 6
---------
(出力)
4

*/



ll solve(vll a) {
	n = a.size();
	vector<ll> dp(n+1, M);
	for (ll i = 0; i<n; i++) {
		ll tmp = upper_bound(all(dp), a[i]) - dp.begin();
		dp[tmp] = a[i];
	}
	for (int i = n; i >= 0;i--) {
		if (dp[i] != M) {
			return i + 1;
		}
	}
}

int main() {
	INIT();
	cin >> n;
	vll v(n);
	rep(i, n) cin >> v[i];
	reverse(all(v));
	cout << solve(v) << endl;
	return 0;
}
