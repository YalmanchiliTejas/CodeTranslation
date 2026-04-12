#include <bits/stdc++.h>
using namespace std;


int a[200005];
long long dp[200005];
long long pom[200005];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	if (n % 2 == 0){
		long long s1 = 0, s2 = 0;
		for (int i = 1; i <= n; i += 2)
			s1 += a[i];
		for (int i = 2; i <= n; i += 2)
			s2 += a[i];
		long long wynik = max(s1,s2);

		dp[1] = a[1];
		for (int i = 2; i <= n; ++i)
			dp[i] = dp[i-2] + a[i];

		pom[n] = a[n];
		for (int i = n-1; i >= 1; --i){
			if (i % 2 == 1)
				pom[i] = pom[i+2] + a[i];
	 		else
	 			pom[i] = max(pom[i+2]+a[i],pom[i+3]+a[i]);
		}


		for (int i = 1; i < n; ++i){
			long long s = 0;
			if (i % 2 == 1){
				s = dp[i] + (dp[n] - dp[i+1]);
				wynik = max(wynik, s);
			}
		}
		cout << wynik << "\n";
		return 0;
	}

	dp[1] = a[1];
	for (int i = 2; i <= n; ++i)
		dp[i] = dp[i-2] + a[i];
	long long wynik = -1e18;

	pom[n] = a[n];
	for (int i = n-1; i >= 1; --i){
		if (i % 2 == 1)
			pom[i] = pom[i+2] + a[i];
 		else
 			pom[i] = max(pom[i+2]+a[i],pom[i+3]+a[i]);
	}


	for (int i = 1; i < n; ++i){
		long long s = 0;
		if (i % 2 == 1){
			s = dp[i] + (dp[n-1] - dp[i+1]);
			wynik = max(wynik, s);

			s = dp[i] + (dp[n] - dp[i+2]);
			wynik = max(wynik, s);

			s = dp[i] + pom[i+3];
			wynik = max(wynik, s);
		}
		if (i % 2 == 0){
			s = dp[i] + pom[i+3];
			wynik = max(wynik, s);
		}

		//cout << s << ": " << i << "\n";
	}
	wynik = max(wynik, dp[n]-dp[1]);
	wynik = max(wynik, dp[n-1]);
	cout << wynik << "\n";
}