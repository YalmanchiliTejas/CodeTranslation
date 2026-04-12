#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<set>
using namespace std;
int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
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
typedef long long ll;

const ll M = 1000000007;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)

ll mpow(ll x, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
		n = n >> 1;
	}
	return ans;
}

ll comb(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
int main() {
	ll n, m, i, j, k, ans=0;
	cin >> n >> m>>k;
	fac[0] = 1;
	ifac[0] = 1;
	for (ll i = 0; i < 300000; i++) {
		fac[i + 1] = fac[i] * (i + 1) % M; // n!(mod M)
		ifac[i + 1] = ifac[i] * mpow(i + 1, M - 2) % M; // k!^{M-2} (mod M) ←累乗にmpowを採用
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			ans = (ans+(m - j)*(m - j + 1) / 2 % M*n%M + (n - i)*(n - i + 1) / 2 % M+(i-1)*i/2%M*(m-j)%M+(n-i)*(n-i+1)/2%M*(m-j)%M) % M;
	ans = ans * comb(n*m - 2, k - 2)%M;
	cout << ans << endl;
}