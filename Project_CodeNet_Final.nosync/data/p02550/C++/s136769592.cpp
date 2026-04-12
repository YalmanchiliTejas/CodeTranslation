#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main() {
	u64 N, X, M;
	cin >> N >> X >> M;

	if(N < M) {
		u64 ans = 0;

		for(u64 i=0; i<N; i++) {
			ans = ans + X;
			X = (X * X) % M;
		}
		
		cout << ans << endl;
		return 0;
	}

	vector<bool> l(M);
	u64 lsum = 0;
	u64 nX = X;

	// find loop
	for(u64 i=0; i<M; i++) {
		if(nX == 0) {
			cout << lsum << endl;
			return 0;
		}
		
		if(l[nX]) break;
		
		l[nX] = true;
		lsum = lsum + nX;
		nX = (nX * nX) % M;
	}

	// before loop
	u64 lcnt = 0;
	u64 ans = 0; 
	for(u64 i=X; i!=nX; i=i*i%M) {
		ans += i;
		lcnt++;
	}
	N-= lcnt;

	// in loop
	lsum = nX;
	lcnt = 1;

	for(u64 i=nX*nX%M; i!=nX; i=i*i%M) {
		lcnt++;
		lsum += i;
	}

	ans += (N / lcnt) * lsum;

	// extra
	u64 a = nX;
	for(u64 i=0; i<N%lcnt; i++) {
		ans += a;
		a = (a * a) % M;
	}

	cout << ans << endl;	
	return 0;
}