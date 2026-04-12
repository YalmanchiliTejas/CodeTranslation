#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
int main(void) {
	int N,M,i,j,a,b,ok,okk,ans=0;
	int A[60];
	int B[60];
	
	scanf("%d %d", &N,&M);
	vector<int>v(N);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		A[i] = a;
		B[i] = b;
		A[i + M] = b;
		B[i + M] = a;
	}
	for (i = 0; i < N; i++) {
		v[i] = i + 1;
	}
	do {
		if (v[0] != 1) { break; }
		okk = 1;
		for (i = 1; i < N; i++) {
			ok = 0;
			for (j = 0; j < M*2; j++) {
				if (v[i - 1] == A[j] && v[i] == B[j]) {ok = 1; break;}
			}
			if (ok == 0) { okk = 0; break; }
		}
		if (okk == 1) { ans++; }

	} while (next_permutation(v.begin(), v.end()));     // 次の順列を生成
	printf("%d", ans);

	
	return 0;
}