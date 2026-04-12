#include <bits/stdc++.h>

using namespace std;
 
int main() {

	int n;
	cin>>n;

	int mod = (1e9)+7;

	vector<int> A(n+1);
	for(int i=1; i<=n; i++) cin>>A[i];

	vector<long long int> suffix_sum(n+1);
	
	suffix_sum[n] = A[n];
	for(int i=n-1; i>=1; i--) suffix_sum[i] = (A[i] + suffix_sum[i+1]) % mod;

	long long int ans = 0;

	for(int i=1; i<=n-1; i++) {

		ans = (ans + (A[i] * suffix_sum[i+1]) % mod) % mod;
	}

	cout<<ans<<endl;

	return 0;
}