#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	ll N, K; cin >> N >> K;

	if (K == 0) {
		cout << N*N << endl;
		return 0;
	}

	ll sum=0;
	for (ll b = 1; b <= N; b++) {
		ll c = (N+1)/b, d = (N+1)%b;
		//cout << c <<" "<< d << endl;
		if(b-K >= 0) sum += (b-K)*c;
		if(d-K >= 0) sum += d-K;
	}

	cout << sum << endl;
}
