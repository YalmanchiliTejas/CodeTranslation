#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(llint i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define sort(s) sort(s.begin(),s.end())
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<int>>
#define UF  UnionFind
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！


//2のn乗を求めるよ！！！
int ni(int n) {
	if (n == 0)return 1;
	int x = ni(n / 2);
	x *= x;
	if (n % 2 == 1)x *= 2;
	return x;
}

//フィボナッチ数列のx番目を求めるよ！
llint f(int x, vector<llint> &s) {
	if (x == 0)return 0;
	if (x == 1)return 1;
	if (s[x] != 0)return s[x];
	return  s[x] = f(x - 1, s) + f(x - 2, s);
	
}

//aとｂの最大公約数を求めるよ！
llint gcd(llint a, llint b) {
	if (a < b)swap(a, b);
	if (b == 0)return a;
	return gcd(b, a % b);
}



// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// mod. m での a の逆元 a^{-1} を計算するよ！
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}


//aCbをmod.mで割った余りを求める
ll int c(ll int a, ll int b, ll int m) {
	ll int ans = 1;
	for (ll int i = 0; i < b; i++) {
		ans *= a - i;
		ans %= m;
	}
	for (ll int i = 1; i <= b; i++) {
		ans *= modinv(i, m);
		ans %= m;
	}
	return ans;
}

//m進数のn桁を全列挙やで
void dfs(int m, int n,hei(int) a) {
	stack<string> st;
	st.push("");
	while (!st.empty()) {
		string now = st.top();
		st.pop();
		if (now.size() == n) cout << now << endl;
		else {
			for (int i = m - 1; i >= 0; i--) {
				string next = now + to_string(i);
				st.push(next);
			}
		}
	}

}
void press(vector<int>& v) { v.erase(unique((v).begin(), (v).end()), v.end()); }

llint min(llint a, llint b) {
	if (a < b)return a;
	return b;
}
llint max(llint a, llint b) {
	if (a < b)swap(a, b);
	return a;
}
llint p(int n) {
	if(n==1)return 1;
	return n * p(n - 1);
}
struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}
	int size(int a) {
		return par[root(a)];
	}

	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 0;
	int z = 10000000000;
	if (a + b <=2* c)ans = a * x+b*y;
	else {
		int n = min(x, y);
		int m = max(x, y);
		ans=2*c*n;
		if (m == x)ans += a * (m - n);
		else ans += b * (m - n);
		z = 2 * c * m;
	}
	ans = min(z, ans);
	cout << ans << endl;
	return 0;
}
