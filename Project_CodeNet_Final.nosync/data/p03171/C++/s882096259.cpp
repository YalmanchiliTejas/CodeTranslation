#include <bits/stdc++.h>

using namespace std;
#define DIM  3007
#define DIM2 100007
#define INF 10E16
#define MAXN 107
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
//typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};
ll n, A[DIM], D[DIM][DIM],sum[DIM][DIM];

int main()

{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> A[i];
	for (int i = 1; i <= n; i++) {
		ll r = 0;
		for (int j = i; j <= n; j++) {
			r += A[j];
			sum[i][j] = r;
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; j++) {
			D[i][j] = sum[i][j] - min(D[i + 1][j], D[i][j - 1]);
		}
	}
	cout << D[1][n] - min(D[2][n], D[1][n - 1]) << endl;
	
}
