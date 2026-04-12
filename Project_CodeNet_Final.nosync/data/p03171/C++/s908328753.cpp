//by Top1
#include <bits/stdc++.h>
     
#define f first
#define s second
#define int long long
#define ld long double
#define ull unsigned long long
#define pii pair <int, int>
#define pll pair <long, long>
#define mp make_pair
#define pb push_back
#define pf push_front
#define pp pop_back
#define rev reverse
#define all(s) s.begin(), s.end()
#define sz(s) (int)s.size()
#define forn(i, a, b) for (int i = a; i <= b; i++)
#define boost ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define nxtp next_permutation
#define pvtp prev_permutation
#define KZ return 
#define x1 x21212121
#define y1 y21212121
#define sqr(x) x * x 
 
const int inf = (1e9) + 1;
const int mod = 1e9 + 7;
const int maxn = 3e3 + 111;
     
using namespace std;

int n, q, a[maxn], dp[maxn][maxn], sum, pref[maxn];
                           
int get(int l, int r){
	return pref[r] - pref[l - 1];
}

void solve(){
	cin >> n;

	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i][i] = a[i];
		sum += a[i];
		pref[i] = pref[i - 1] + a[i];
	}

	for (int len = 2; len <= n; len++)
		for (int l = 1, r = l + len - 1; r <= n; l++, r++)
			dp[l][r] = max(get(l, r) - dp[l + 1][r], get(l, r) - dp[l][r - 1]);
	
	cout << 2 * dp[1][n] - sum;	
}

main(){
    boost;
	    
	q = 1;

	while (q--){
		solve();
	}
}