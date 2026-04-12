#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_upd>
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
*/
using namespace std;

#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()

const LL MOD = 998244353;
const LD EPS = 0.0000001 ;

LL pows(LL a, LL b)
{
	if (b == 0) return 1LL;
	LL temp = pows(a, b / 2);
	temp = (temp * temp) % MOD;
	if (b % 2) temp = (temp * a) % MOD;
	return temp;
}

const int N = 3005;

LL dp[N][N];

int arr[N];
int n;

LL solve(int idx, int sum)
{
	if (sum == 0) return (n - idx + 1LL);
	if (idx >= n) return 0;
	if (sum < 0) return 0;
	LL &ans = dp[idx][sum];
	if (ans != -1) return ans;
	ans = 0;
	ans = (solve(idx + 1, sum) + solve(idx + 1, sum - arr[idx])) % MOD;
	return ans;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	int s; cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	LL ans = 0;

	for (int i = 0; i < n; i++){
		LL temp = solve(i + 1, s - arr[i]);
		temp = (temp * (i + 1LL)) % MOD;
		ans = (ans + temp) % MOD;
	}

	cout << ans << endl;

	return 0;
}


