#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<numeric>
#include<limits>
#include <cstdint>
#include<stack>
#include<queue>
using namespace std;
#define ll long long int
#define rep(N) for(ll i=0;i<N;i++)
#define rep2(N1,N2) for(ll i=0;i<N1;i++)for(ll j=0;j<N2;j++)
#define rep3(N1,N2,N3)for(ll i=0;i<N1;i++)for(ll j=0;j<N2;j++)for(ll k=0;k<N3;k++)
#define For(i,N) for(ll i=0;i<N;i++)

void yn(bool b) {
	if (b)printf("yes\n");
	else printf("no\n");
}

void Yn(bool b) {
	if (b)printf("Yes\n");
	else printf("No\n");
}

void YN(bool b) {
	if (b)printf("YES\n");
	else printf("NO\n");
}

int ctoi(char c) {
	return c - '0';
}

ll kai(ll x) {
	ll a = 1;
	if (x <= 0)
		return 1;
	else {
		for (ll i = 0; i < x; i++)
			a = a * (i + 1);
		return a;
	}
}

ll rui(ll x, ll y) {
	ll a = 1;
	for (ll i = 0; i < y; i++)
		a = a * x;
	return a;
}
const int nmax = 150;
int cccc[nmax][nmax];
ll comb(ll n, ll k) {
	if (n < k) {
		cout << "error n<k" << endl;
		return -1;
	}
	if (cccc[n][k] > 0)return cccc[n][k];
	if (k == 0 || n == k)return 1;
	return cccc[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
}

ll keta(ll a) {
	ll i = 1;
	while (1) {
		if (a < pow((ll)10, i))
			return i;
		i++;
	}
}
vector<ll> v;
ll n, m;
//m進数全探索
ll inc(ll a = n - 1) {
	if (a == 0 && v[0] == m) {
		v[0] = -1;
		return v[0];
	}
	if (v[a] == m) {
		v[a] = 0;
		inc(a - 1);
		return v[a];
	}
	else {
		++v[a];
		return v[a];
	}
}

ll mod = 1000000007;

ll modpowl(ll a, ll b) {
	if (b == 0) {

		return 1;
	}
	if (b == 1) {

		return a;
	}
	if (b >= 2) {
		if (b % 2 == 0) {
			ll c = modpowl((a*a) % mod, b / 2);
			c = c % mod;

			return c;
		}
		else {
			ll c = (modpowl((a*a) % mod, b / 2) % mod)*a;
			c = c % mod;

			return c;
		}
	}
}
ll gyo(ll N, ll A, ll B, ll y) {
	if (A != y && B != y)
		return y;
	else if (A == y)
		return B;
	else
		return A;
}

ll retsu(ll N, ll A, ll B, ll x) {
	if (A != x && B != x)
		return x;
	else if (A == x)
		return B;
	else
		return A;
}

pair<ll,ll> tenchi(ll x, ll y) {
	return make_pair(y, x);
}
int main() {
	cout.precision(20);
	ll N, M;
	cin >> N >> M;
	ll flag = 1;
	if (N != M)
		flag = 0;
	Yn(flag);
}


