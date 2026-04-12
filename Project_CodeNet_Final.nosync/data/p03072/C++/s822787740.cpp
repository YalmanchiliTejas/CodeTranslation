#include <bits/stdc++.h>
using namespace std;


int main(){	
	int N;
	scanf("%d",&N);
	vector<int> H(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%d",&H[i]);
	}
	int res = 0, M = 0;
	for (int i=0; i<N; i++) {
		if (M<=H[i]) res++;
		M = max(M, H[i]);
	}
	cout << res << endl;
	return 0;
}

