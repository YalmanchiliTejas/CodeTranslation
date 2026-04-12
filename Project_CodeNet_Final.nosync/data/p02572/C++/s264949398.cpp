#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else { return gcd(b, a % b); } }
ll mod(ll a) { return a % 1000000007; }
#define K 1000000007


int main() {
	ll n;
	cin >> n;
	vector<ll> A(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	ll sum = 0;
	for (int i = 0; i < n; i++) sum = (sum + A[i])%K;
	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		sum = (sum - A[i])%K;
		ans = (ans + ((A[i]-K) * (sum-K))%K)%K;
	}
	cout << ans % K << endl;
	return 0;
}