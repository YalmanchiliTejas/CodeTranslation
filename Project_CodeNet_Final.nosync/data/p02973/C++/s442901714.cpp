#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 998244353, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;

ll dp[100001];
ll arr[100000];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, N){
		cin >> arr[i];
	}
	reverse(arr, arr+N);
	rep(i, N+1){
		dp[i] = MAX;
	}
	rep(i, N){
		*upper_bound(dp, dp + N, arr[i]) = arr[i];
	}
	cout << (lower_bound(dp, dp + N, MAX) - dp) << endl;
}