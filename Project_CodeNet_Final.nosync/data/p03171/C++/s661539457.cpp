#include<bits/stdc++.h>
 
/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
*/
using namespace std;
 
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
const LL MOD = 1000000000 + 7;
const LD EPS = 0.0000001 ;
#define MPP(a, b, c) MP(MP(a, b), c)
#define PII pair<pair<LL,LL>, LL>
 
LL pows(LL a, LL b)
{
	if (b == 0) return 1LL;
	LL temp = pows(a, b / 2);
	temp = (temp * temp) % MOD;
	if (b % 2) temp = (temp * a) % MOD;
	return temp;
}

const int N = 3001;

LL dp[N][N];
LL arr[N];
bool vis[N][N];

LL solve(int l, int r)
{
	if (l == r) return arr[l];
	if (r - l == 1) return abs(arr[r] - arr[l]);
	if (l > r) return 0;
	if (vis[l][r]) return dp[l][r];
	vis[l][r] = true;
	LL &ans = dp[l][r];
	if (solve(l + 2, r) - arr[l + 1] > solve(l + 1, r - 1) - arr[r]){
		ans = arr[l] - arr[r] + solve(l + 1, r - 1);
	} else {
		ans = arr[l] - arr[l + 1] + solve(l + 2, r);
	}
	LL temp2;
	if (solve(l + 1, r - 1) - arr[l] > solve(l, r - 2) - arr[r - 1]){
		temp2 = arr[r] - arr[r - 1] + solve(l, r - 2);
	} else {
		temp2 = arr[r] - arr[l] + solve(l + 1, r - 1);
	}
	ans = max(ans, temp2);
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    cout << solve(1, n) << endl;

	return 0;
}