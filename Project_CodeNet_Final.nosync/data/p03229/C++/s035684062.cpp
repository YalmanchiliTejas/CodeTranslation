#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main () {
	ll N;
	cin >> N;	
	vector<ll> A(N); 
	for (ll i=0; i<N; ++i) cin >> A[i];
	sort(A.begin(), A.end());

	vector<ll> I(N);
	// N == 3 => 3rd, 1st, 2nd ... or ... 1st, 3rd, 2nd
	// N == 4 => 2nd, 4th, 1st, 3rd ... or ... 3rd, 1st, 4th, 2nd ... they are the same. symmetric
	/*
	(1)
	I[N/2] = 0; 
	I[N/2 - 1] = N-1;
	I[N/2 + 1] = N-2;
	I[N/2 - 2] = 1;
	I[N/2 + 2] = 2;
	I[N/2 - 3] = N-3;
	I[N/2 + 3] = N-4;
	I[N/2 - 4] = 3;
	I[N/2 + 4] = 4;

	... or ...

	(2)
	I[N/2] = N-1; 
	I[N/2 - 1] = 0;
	I[N/2 + 1] = 1;
	I[N/2 - 2] = N-2;
	I[N/2 + 2] = N-3;
	I[N/2 - 3] = 2;
	I[N/2 + 3] = 3 
	I[N/2 - 4] = N-4;
	I[N/2 + 4] = N-5;

	that is, shifts array I one element to right with perioding boundary

	*/

	ll m = N/2;
	I[m] = 0;
	ll counter = 1;
	bool first_flag = true; 
	ll w = 1;
	while (counter < N) {
		ll temp;
		if(first_flag) {
			if (w % 2 == 0) {
				temp = w - 1;
			} else {
				temp = N - w;
			}
			I[m-w] = temp;
			first_flag = false;
		} else {
			if (w % 2 == 0) {
				temp = w; 
			} else {
				temp = N - w - 1; 
			}
			I[m+w] = temp;
			first_flag = true;
			w++;
		}
		counter++;
	}
	/*
	for (ll i=0;i<N;++i) cout << I[i] << " ";
	cout << endl;
	*/

	ll ans = 0;
	for (ll i=1; i<N; ++i) {
		ans += abs(A[I[i]] - A[I[i-1]]);
	}
	if (N % 2 == 1) {
		ll ans2 = 0;
		ans2 += abs(A[I[N-1]] - A[I[0]]);
		for (ll i=1; i<N-1; ++i) {
			ans2 += abs(A[I[i]] - A[I[i-1]]);
		}
		ans = max(ans, ans2);
	}
	cout << ans << endl;
	return 0;
}

