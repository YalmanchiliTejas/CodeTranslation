#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 924844033;
const ll INF = 1e18;
int n, m;
#define maxn 1010

ll tab[maxn], tmp[maxn];

ll bs(ll co, ll ode)
{
	if (co < n) return 0;
	ll x = 0, y = 2e16;
	while (x < y)
	{
		//cout << x << ' ' << y << ' ' << co << ' ' << ode << endl;
		ll sr = (x + y)/2;
		if (co - sr * ode >= n) x = ++sr;
		else y = sr;
	}
	//cout << "Bins: " << co << ' ' << ode << ' ' << x << endl;
	return x;
}

bool check(ll k)
{
	ll ode = n + 1;
	FOR(i, 1, n) tmp[i] = tab[i] + k;
	ll trzeba = 0;
	FOR(i, 1, n) trzeba += bs(tmp[i], ode);
	if (trzeba <= k) return 1;
	return 0;
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	ll x = 0, y = INF;
	//cout << check(1) << endl;
	while (x < y)
	{
		ll sr = (x + y) / 2LL;
		bool odp = 0;
		FOR(j, 0, 2500)
		{
			if (sr - j < x) break;
			if (check(sr - j)) odp = 1;
		}
		if (odp == 0) x = ++sr;
		else y = sr;
	}
	cout << x;
}
