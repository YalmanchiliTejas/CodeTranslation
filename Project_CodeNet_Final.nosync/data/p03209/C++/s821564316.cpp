
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll mod = 1000000007;

//bool operator< (pint a, pint b) {
	//return a.second < b.second;

//}



ll gcd(ll a, ll b) {

	if (b == 0)
		return a;

	return gcd(b, a % b);


}

ll max(ll a, ll b) {
	if (a < b) {
		return b;
	}
	else
		return a;

}

ll min(ll a, ll b) {
	if (a < b)
		return a;

	return b;
}




pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<pint> list;










void floyd(int N, ll** d) {

	rep(k, N+1){
		rep(i, N+1) {
			if (d[i+1][k+1] == inf) continue;
			rep(j, N+1) {
				if (d[j+1][k+1] == inf) continue;

				d[i+1][j+1] = min(d[i+1][j+1], d[i+1][k+1] + d[j+1][k+1]);

			}

		}
	}




}


ull modpow(ull a, ull b) {
	ll retval = 0;

	if (b == 0) { return 1; }

	else if (b % 2 == 0) {
		retval = modpow(a, b / 2) % mod;
		return (retval * retval) % mod;
	}

	else {
		
		return ((a % mod) * modpow(a, b - 1)) % mod;
	}
}

ull modkaijou(ull a) {

	if (a == 1 || a == 0) { return 1; }

	ll retval = 1;

	for (ull i = a; i >= 1; i--) {
		retval = (retval * (i % mod)) % mod;
	}

	return retval % mod;
}

ull modcomb(ull a, ull b) {

	if (a == 0 || b == 0) return 1;

	return (((modkaijou(a) * modpow(modkaijou(a-b), mod - 2)) % mod) * modpow(modkaijou(b), mod - 2)) % mod;
}


vector<pint> query;

stack<int> to_1;


class DisjointSet {
public:
	vector<int> p, rank, num;


	DisjointSet() {}

	DisjointSet(int size) {
		rank.resize(size, 0);
		p.resize(size, 0);
		num.resize(size, 0);
		rep(i, size) { p[i] = i; rank[i] = 0; num[i] = 1; }
	}

	bool same(int x, int y) {

		return findSet(x) == findSet(y);

	}

	void unite(int x, int y) {
		link(findSet(x), findSet(y));
	}

	void link(int x, int y) {
		if (rank[x] > rank[y]) {

			p[y] = x;
			num[x] += num[y];

		}

		else {
			p[x] = y;
			num[y] += num[x];
			if (rank[x] == rank[y]) {

				rank[y]++;
			}

		}


	}


	ll NumberOfElements(int x) {

		return num[findSet(x)];

	}


	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]);
			num[x] = 1;
		}

		return p[x];
	}



};



ll s[100005], t[100005], anslist[100005];

ll b[100], a[100];



ll dfs(ll N, ll X) {

	if (X <= 0)
		return 0;
	if (N == 0) {
		return 1;
	}

	else if (X >= b[N - 1] + 2 && X < b[N]) {

		return a[N - 1] + 1 + dfs(N - 1, X - b[N - 1] - 2);
	}

	else if (X > 0 && X < b[N - 1] + 2) {
		return dfs(N - 1, X - 1);
	}

	else {
		return a[N];
	}

}





int main() {
	ll N, X;

	cin >> N >> X;

	b[0] = 1;
	a[0] = 1;

	rep(i, 50) {
		a[i + 1] = 2 * a[i] + 1;
		b[i + 1] = 2 * b[i] + 3;
	}
	
	cout << dfs(N, X) << endl;
	
	return 0;
}