#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound
#define treap_pair pair<treap*, treap*>
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
 
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 1e4 + 2;
const int M = 4e5;
const ll mod = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e16;
 
void data() {
	#ifdef PC
		freopen("main.in", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
}

char k[N];
int d, n, dp[N][102][2];
 
int add(int a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	if (a < 0)
		a += mod;
   	return a;
}

void add_self(int &a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	if (a < 0)
		a += mod;
}

int main() {
	data();  	
	scanf("%s", &k);
	scanf("%d", &d);
	n = strlen(k);
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < d; ++j) {
			for (int l = 0; l < 10; ++l) {
				if (l < k[i] - '0') {
					add_self(dp[i + 1][(j + l) % d][1], dp[i][j][0]);
					add_self(dp[i + 1][(j + l) % d][1], dp[i][j][1]);
				}
				if (l == k[i] - '0') {
					add_self(dp[i + 1][(j + l) % d][0], dp[i][j][0]);	
					add_self(dp[i + 1][(j + l) % d][1], dp[i][j][1]);
				}
				if (l > k[i] - '0') {
					add_self(dp[i + 1][(j + l) % d][1], dp[i][j][1]);
				}
			}
		}
	}
	printf("%d", add(dp[n][0][0], add(dp[n][0][1], -1)));
}
 
/*
	Timus: 288481RF
	CodeForces: fractal
*/