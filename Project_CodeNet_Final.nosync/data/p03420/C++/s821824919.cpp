#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ans;
int main()
{
	cin >> n >> k;
	for(ll b=k+1; b<=n; ++b){
		ll qmx = n/b;
		while(qmx * b + (b-1) > n) --qmx;
		ans += max(0ll, (++qmx) * (b-k) - (k==0));
		ans += max(0ll, n-b*qmx-k+1);
	}
	cout << ans << endl;
	return 0;
}
