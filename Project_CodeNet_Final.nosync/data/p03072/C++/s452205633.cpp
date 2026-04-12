
#include <bits/stdc++.h>
using namespace std;

// io
#define get(i) scanf("%d", &i)
#define flush fflush(stdin)

// manipulations
#define f(i, n) for (int i = 0; i < n; i++)
#define fr(i, n) for (int i = n - 1; i >= 0; i--)
#define ff(i, a, b) for (int i = a; i <= b; i++)
#define lowbit(x) (x & -x)
#define sz(x) int((x).size())

// built-in
#define bitcount __builtin_popcount
#define gcd __gcd

// short
#define pb push_back
#define fill(arr, a) memset(arr, a, sizeof(arr))

// useful bits
#define IN(i, l, r) (l <= i && i <= r)
#define relax(a, b) (a) = max((a), (b))
#define relaxi(a, b) (a) = min((a), (b))

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long ll;
typedef long double ld;

ll modpow(ll a, ll b, ll mod = (ll) (1e9 + 7)) 
{if (!b) return 1; a %= mod; return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;}

// for rand
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// use uniform_int_distribution<int>(0, i)(rng)


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	int h[n];
	f(i,n) {
		cin >> h[i];
	}
	int cnt = 0;
	f(i,n) {
		ff(j,0,i) if (h[j]>h[i]) goto end;
		cnt++;
end:{}
	}
	cout << cnt << endl;


	return 0;
}

