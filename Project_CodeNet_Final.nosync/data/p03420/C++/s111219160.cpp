#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){	
	long long K;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&K);
	ll res = 0;
	for (ll b=1; b<=N; b++) {
		if (b > K) res += N/b*(b-K)+max(0LL, N%b-max(0LL, K-1));
	}
	cout << res << endl;
	return 0;
}

