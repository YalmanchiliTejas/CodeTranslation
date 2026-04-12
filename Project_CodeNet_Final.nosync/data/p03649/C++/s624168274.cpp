#include <stdio.h>

int N;
long long A[55];

int main()
{
	scanf ("%d",&N);
	for (int i=0;i<N;i++) scanf ("%lld",&A[i]);
	long long ans = 0;
	while (1){
		bool ch = 0;
		for (int i=0;i<N;i++) if (A[i] >= N){
			long long down = A[i] / N; A[i] %= N;
			if (down){
				ch = 1;
				for (int j=0;j<N;j++) if (i != j) A[j] += down;
				ans += down;
			}
		}
		if (!ch) break;
	}
	printf ("%lld\n",ans);

	return 0;
}