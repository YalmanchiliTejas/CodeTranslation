#include	<bits/stdc++.h>
using	namespace	std;

int	main() {
	long N, K;
	cin >>N >>K;
	if (0==K) {
		cout <<N*N <<endl;
		return 0;
	}
	long S=0;
	for (long b=N; b>=K+1; b--) {
		/*
		for (long c=K; c<b; c++)
			S +=(N+b-c)/b;
		*/
		S += (N/b)*(b-K);
		if (N%b>=K)
			S += (N%b)-K+1;
	}
	cout <<S <<endl;
	return 0;
};
