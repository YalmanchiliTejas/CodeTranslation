#include<bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
 
typedef long long ll;
typedef unsigned long long int ull;
typedef long double ld;
 
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef pair<string, string> ss;
typedef pair<int, ss> iss;
 
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ld> vld;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, pii>> vpiii;
 
typedef map<string, string> mss;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, ll> mill;
typedef map<int, vpii> mivpii;

const int MAXN = 1e4;
const int MAXD = 100;
const int TIGHT = 2;
const int UNSET = -1;
const int MOD = 1e9 + 7;

int dp[MAXN + 1][MAXD + 1][TIGHT];
int d[MAXN + 1];

string K;
int D, N;

void fast_io() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int solve(int pos, int mod, bool r) {
	if(pos == N) return (mod == 0);
	if(dp[pos][mod][r] != UNSET) return dp[pos][mod][r];

	int lim = (r ? d[pos] : 9);
	int sum = 0;
	
	for(int i = 0; i <= lim; i++) {
		bool nr = (i == d[pos]) ? r : 0;
		sum += solve(pos + 1, (mod + i) % D, nr);
		if(sum >= MOD) sum -= MOD;
	}
	
	return dp[pos][mod][r] = sum;
}

int main() {
	fast_io();
//	freopen("input/dp_s.txt", "r", stdin);

	memset(dp, UNSET, sizeof(dp));
	cin >> K >> D;
	
	N = K.length();
	for(int i = 0; i < N; i++) 
		d[i] = K[i] - '0';
		
	int ans = (solve(0, 0, 1) - 1) % MOD;
	if(ans < 0) ans += MOD;
	cout << ans << '\n';
	
	return 0;
}