#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

//昔の自分は頭いいなぁ

#define PT pair<ll, int>
int N, M, S, T;
int to[400001], d[400001], ne[400001], he[100001];
ll D[100001];
int dp1[100001], dp2[100001];
const int mod = 1e9 + 7;
int search1(int A) {
	if (dp1[A]) return dp1[A] - 1;
	int ret = 0;
	for (int i = he[A]; i; i = ne[i]) {
		if (D[to[i]] == D[A] + d[i]) {
			ret = ret + search1(to[i]);
			if (ret >= mod) ret -= mod;
		}
	}
	dp1[A] = ret + 1;
	return ret;
}

int search2(int A) {
	if (dp2[A]) return dp2[A] - 1;
	int ret = 0;
	for (int i = he[A]; i; i = ne[i]) {
		if (D[to[i]] == D[A] - d[i]) {
			ret = ret + search2(to[i]);
			if (ret >= mod) ret -= mod;
		}
	}
	dp2[A] = ret + 1;
	return ret;
}

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	N = getint();
	M = getint();
	S = getint();
	T = getint();
	int k = 1;
	rep(i, M) {
		int u = getint(), v = getint(), dt = getint() * 2;
		to[k] = v;
		d[k] = dt;
		ne[k] = he[u];
		he[u] = k++;
		to[k] = u;
		d[k] = dt;
		ne[k] = he[v];
		he[v] = k++;
	}

	rep1(i, N) D[i] = 1e18;
	D[S] = 0;

	priority_queue<PT, vector<PT>, greater<PT>> que;
	que.push(mp(0, S));
	while (que.size()) {
		PT p = que.top();
		que.pop();
		int i = p.second;
		if (D[i] != p.first) continue;
		for (int t = he[i]; t; t = ne[t]) {
			int j = to[t];
			ll tmp = D[i] + d[t];
			if (D[j] > tmp) {
				D[j] = tmp;
				que.push(mp(tmp, j));
			}
		}
	}

	ll hanbun = D[T] / 2;
	ll kotae = 0;
	dp1[T] = 2;
	dp2[S] = 2;
	rep1(A, N) {
		if (D[A] == hanbun) {
			ll kari = (ll)search1(A) * search2(A) % mod;
			kotae += kari * kari % mod;
		}
		else if (D[A] < hanbun) {
			for (int i = he[A]; i; i = ne[i]) {
				if (D[A] + d[i] > hanbun && D[A] + d[i] == D[to[i]]) {
					ll kari = (ll)search1(to[i]) * search2(A) % mod;
					kotae += kari * kari % mod;
				}
			}
		}
	}

	printf("%lld", (((ll)search1(S) * search1(S) - kotae) % mod + mod) % mod);

	Would you please return 0;
}