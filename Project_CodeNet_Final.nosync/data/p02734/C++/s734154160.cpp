#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, s, a, ans, M=998244353, d[3005]={1};
int main() {
	cin >> n >> s;
	while(n--) {
		scanf("%lld", &a);
		if(s >= a) (ans += d[s-a] * (n+1)) %= M;
		for(ll i=s-a-1; i>=0; i--) (d[i+a] += d[i]) %= M;
		d[0]++;
	}
	cout << ans;
	return 0;
}