#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define scch(x) scanf("%c", &x)
#define scld(x) scanf("%Lf", &x)
#define scll(x) scanf("%lld", &x)

int main() {
	ll n, k;
	cin >> n >> k;
	ll result = 0;
	for (ll i=1; i<=n; i++) {
		ll maxsisa = i-1;
		if (maxsisa >= k) {
			ll banyaklengkap = n/i;
			ll subres = 0;
			result+=banyaklengkap*(maxsisa-k+1);
			subres += banyaklengkap*(maxsisa-k+1);
			ll sisagalengkap = n%i;
			//cout << sisagalengkap << endl;
			if (sisagalengkap>=k && k!=0) {
				result+=sisagalengkap-k+1;
				subres+=sisagalengkap-k+1;
			}
			//cout << maxsisa-k+1 << endl;
			//cout << banyaklengkap*(maxsisa-k+1)+sisagalengkap-k+1 << endl;
		}
	}
	if (k!=0)
		cout << result << endl;
	else
		cout << n*n << endl;
	return 0;
}