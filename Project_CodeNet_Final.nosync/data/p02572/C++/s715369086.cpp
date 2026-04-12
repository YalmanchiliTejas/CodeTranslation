#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<functional>
#include<string>
#include<vector>
#include<cstring>
#include<utility>
#include<set>
#include<map>

#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 2e9
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
const double PI = acos(-1);

using namespace std;
ll A[200001];
ll psum[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//	freopen("input.txt", "r", stdin);

	int N; cin >> N;
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
	    cin >> A[i];
		psum[i] = psum[i - 1] + A[i];
	}
	for (int i = 1; i < N; i++) {
		ans += (A[i] * ((psum[N] - psum[i]) % MOD))%MOD;
		ans %= MOD;
	}
	cout << ans;
}
