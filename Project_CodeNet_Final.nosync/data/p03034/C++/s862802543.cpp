#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<ll> s(N);
	rep(i, N) cin >> s[i];

	ll ans = 0;

	for(ll C = 1; C <= N - 1; C++){
		ll sm = 0;
		if((N - 1) % C == 0){
			for(ll k = 1; k * C < N - 1 - k * C; k++){
				sm += s[N - 1 - k * C] + s[k * C];
				ans = max(ans, sm);
			}
		}else{
			for(ll k = 1; N - 1 - k * C > C; k++){
				sm += s[N - 1 - k * C] + s[k * C];
				ans = max(ans, sm);
			}
		}
	}

	cout << ans << endl;

}
