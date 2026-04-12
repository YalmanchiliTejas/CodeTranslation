#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define sz(x) x.size()
#define printarray(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout<<*it<<" "; cout<<endl;
#define rep(n) for (ll i = 0; i < n; i++)
#define repc(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b)/gcd(a, b)
#define int long long int
#define ull unsigned long long

using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 3006;

int fastexpo(int b, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return b;
    int ans = (fastexpo(b,exp/2) % MOD);
    ans *= ans;
    ans %= MOD;
    if(exp % 2 == 1){
        ans *= b;
    }
    ans %= MOD;
    return ans;
}

int n;
int a[MAXN];
int dp[MAXN][MAXN];

int solve(int i, int j, int curr){
	if(i == j){
		return curr * a[i];
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	if(curr > 0){
		return dp[i][j] = max((curr * a[i]) + solve(i+1, j, curr*-1), (curr * a[j]) + solve(i, j-1, curr*-1));
	} else {
		return dp[i][j] =  min((curr * a[i]) + solve(i+1, j, curr*-1), (curr * a[j]) + solve(i, j-1, curr*-1));
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    memset(dp, -1, sizeof(dp));
    FOR(i, 0, n){
    	cin>>a[i];
    }
    cout<<solve(0, n-1, 1)<<endl;
    return 0;
}
