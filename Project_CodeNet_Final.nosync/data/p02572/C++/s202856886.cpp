#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	u64 N;
	cin >> N;

	vector<u64> A(N);
	u64 mod = pow(10, 9) + 7;

	for(u64 i=0; i<N; i++) {
		cin >> A[i];
	}
	
	u64 Asum = 0;
	u64 ans = 0;

	for(s64 i=N-2; i>=0; i--) {
		Asum = (Asum + A[i+1]) % mod;
		ans = (ans + (Asum * A[i]) % mod) % mod;
	}

	cout << ans << endl;

	return 0;	
}