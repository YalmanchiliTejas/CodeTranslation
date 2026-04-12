#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>;
//**関数リスト**//
int ctoi(char c) {
	switch (c) {
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.second < secondElof.second;
}
ll nod(ll F) {
	ll keta = 1;
	while (F / 10 > 0) {
		keta++; F /= 10;
	}
	return keta;
}
ll gcd(ll x, ll y) {
	ll r;
	if (x < y) {
		swap(x, y);
	}
	while (y > 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}
ll isPrime(ll x) {
	ll i;
	if (x < 2) {
		return 0;
	}
	else if (x == 2) {
		return 1;
	}
	else if (x % 2 == 0) {
		return 0;
	}
	else {
		for (i = 3; i * i <= x; i += 2) {
			if (x % 1 == 0) {
				return 0;
			}
		}
		return 1;
	}
}
void eratos(vl isPrime) {
	//(注)isPrimeのサイズはN+1にする！実際にはmain内に配置して使用
	ll i, j;
	for (i = 0; i < isPrime.size(); i++) {
		isPrime[i] = 1;
	}
	isPrime[0] = 0; isPrime[1] = 0;
	for (i = 2; i * i <= isPrime.size() - 1; i++) {
		if (isPrime[i] == 1) {
			j = i * 2;
			while (j <= isPrime.size() - 1) {
				isPrime[j] = 0;
				j = j + i;
			}
		}
	}
}
ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
ll alphabet(char C) {
	ll b = 0; ll key = 0;
	if (C == 'a') { return b; }b++;
	if (C == 'b') { return b; }b++;
	if (C == 'c') { return b; }b++;
	if (C == 'd') { return b; }b++;
	if (C == 'e') { return b; }b++;
	if (C == 'f') { return b; }b++;
	if (C == 'g') { return b; }b++;
	if (C == 'h') { return b; }b++;
	if (C == 'i') { return b; }b++;
	if (C == 'j') { return b; }b++;
	if (C == 'k') { return b; }b++;
	if (C == 'l') { return b; }b++;
	if (C == 'm') { return b; }b++;
	if (C == 'n') { return b; }b++;
	if (C == 'o') { return b; }b++;
	if (C == 'p') { return b; }b++;
	if (C == 'q') { return b; }b++;
	if (C == 'r') { return b; }b++;
	if (C == 's') { return b; }b++;
	if (C == 't') { return b; }b++;
	if (C == 'u') { return b; }b++;
	if (C == 'v') { return b; }b++;
	if (C == 'w') { return b; }b++;
	if (C == 'x') { return b; }b++;
	if (C == 'y') { return b; }b++;
	if (C == 'z') { return b; }
	return -1;
}
void bitSearch(ll n) {
	//実際にはコピーして中身を改変して使う
	ll i;
	for (i = 0; i < pow(2, n); i++) {
		ll p = i;
		for(i = 0; i < n; i++) {
			cout << p % 2; p /= 2;
		}
		cout << endl;
	}
}
void bfs(ll now) {
	//中身は毎回書き換えて使用
	queue<ll> Q;
	Q.push(now);
	ll u;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		//ll v=;
		//Q.push(v);
	}
}
//**定義場所**//
ll i, j, k, l, m, n, N, M, K, H, W;
ll MOD = 1000000007; ll ans = 0;
ll vis[3010][3010]; ll memo[3010][3010];
vl A(3010);
//***********//
//区間が左端Lから右端Rまでの時のdp(初期はR=0/L=N-1)
ll dp(ll L, ll R) {
	if (L > R) return 0;
	//訪問済みであればメモした結果を返すだけ
	if (vis[L][R])return memo[L][R];
	//訪問済みであるかどうか
	vis[L][R] = 1;
	//N-(R-L+1)は今までに削った個数(=偶数なら次のターンは太郎)
	ll diff = N - (R - L + 1);
	ll res = 0;
	//先手か後手かの判定
	if (diff % 2 == 0) {
		//X-Yの最大化
		res = -1000000000000000;
		res = max(res, max(dp(L + 1, R) + A[L], dp(L, R - 1) + A[R]));
	}
	else {
		//X-Yの最小化
		res = 10000000000000000;
		res = min(res, min(dp(L + 1, R) - A[L], dp(L, R - 1) - A[R]));
	}
	return memo[L][R] = res;
}
int main() {
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << dp(0, N - 1);
}