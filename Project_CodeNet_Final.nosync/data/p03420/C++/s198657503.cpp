#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;
const int MOD = 998244353;

int main()
{
	int N, K;
	cin >> N >> K;
	ll ans = 0;
	for (int b = K + 1; b <= N; b++) {
		int num = b - K;
		ans += num * (N / b);
		num = N % b;
		ans += max(num - K + 1, 0);
	}
	if (K == 0) cout << (ll)N * N << endl;
	else cout << ans << endl;
}
