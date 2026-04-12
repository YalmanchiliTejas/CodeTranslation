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
const int MOD = 998244353;
const ll INF = 1000000000000000000;

ll A[200010];
int main()
{
	int N;
	cin >> N;
	ll sum = 0;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans = (ans + (sum % mod) * A[i]) % mod;
		sum += A[i];
	}
	cout << ans << endl;
}