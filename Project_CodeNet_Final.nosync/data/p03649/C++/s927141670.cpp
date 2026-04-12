#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

typedef long long ll;
const ll INF = 1000000000000000000ll;
const ll MOD = 1000000007ll;
const double EPS = 1e-8;

bool check_max(int n, vector<ll> a){
	ll ma = -1;
	for(int i=0; i<n; i++){
		ma = max(ma, a[i]);
	}
	if(ma <= n-1) return false;
	else return true;
}

/*
ll solve(int n, vector<ll> a){
	ll ans = 0;
	while(check_max(n, a)){
		ll ma = -1;
		int id = -1;
		for(int i=0; i<n; i++){
			if(ma < a[i]){
				ma = a[i];
				id = i;
			}
		}
		a[id] -= a.size();

		for(int i=0; i<n; i++){
			if(i != id){
				a[i]++;
			}
			//printf("%d ", a[i]);
		}
		//puts("");
		ans++;
	}
	return ans;
}
*/

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	//cout << solve(n, a) << endl;

	
	/*
	int n;
	n = 2;
	vector<ll> a;
	a.pb(1 + ((k+1)/2));
	a.pb(k/2);

	cout << n << endl;
	for(int i=0; i<n; i++){
		if(i != n-1) printf("%lld ", a[i]);
		else printf("%lld\n", a[i]);
	}
	*/

	int n;
	cin >> n;
	vector<ll> a;
	for(int i=0; i<n; i++){
		ll t;
		cin >> t;
		a.pb(t);
	}

	//cout << "exact:" << solve(n, a) << endl;

	ll ans = 0;
	ll cnt = 0;
	while(check_max(n, a)){
		/*
		cnt++;
		if(cnt > 10000){
			break;
		}
		*/
		sort(a.begin(), a.end(), greater<ll>());

		ll mi = INF; 
		for(int i=0; i<n; i++){
			mi = min(mi, a[i]);
		}
		ll sub = max(mi - (n-1), 0ll);
		for(int i=0; i<n; i++){
			a[i] -= sub;
		}
		ans += (long long)sub*(long long)n;
		//cout << "phase1:" << sub << endl;
		//cout << "ans1:" << ans << endl;

		/*
		for(int i=0; i<n; i++){
			printf("%lld ", a[i]);
		}
		puts("");
		*/

		for(int j=0; j<n-1; j++){
			ll m1 = (a[j] - a[j+1] + n)/(n+1);
			ll m2 = (a[j] - (n-1) + n - 1) / n;
			//cout << m1 << endl;
			//cout << m2 << endl;
			sub = max(m1, m2);
			if(sub == 0) continue;

			a[j] -= (long long)n*sub;
			if(a[j] < 0){
				a[j] += n;
				sub--;
			}
			for(int i=0; i<j; i++){
				a[i] += sub;
			}
			for(int i=j+1; i<n; i++){
				a[i] += sub;
			}
			ans += sub;
			//cout << "phase2:" << sub << endl;
			//cout << "ans2:" << ans << endl;
			break;
		}
		/*
		for(int i=0; i<n; i++){
			printf("%lld ", a[i]);
		}
		puts("");
		*/
		//cout << ans << endl;
	}
	cout << ans << endl;

	/*
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			for(int k=0; k<20; k++){
				vector<int> a;
				a.pb(i);
				a.pb(j);
				a.pb(k);

				printf("%3lld ", solve(3, a));
			}
			puts("");
		}
		puts("\n");
	}
	*/



	
	return 0;
}
