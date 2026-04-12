#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int inf = 1 << 30;
const LL INF = 1LL << 60;
const int MaxN = 200005;

int N;
struct Number {
	int val, idx;
	int ans;
}A[MaxN + 5];

bool cmp_val(Number X, Number Y ) {
	return X.val < Y.val;
}

bool cmp_idx(Number X, Number Y ) {
	return X.idx < Y.idx;
}

int main()
{
	while(scanf("%d", &N) != EOF)
	{
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i].val);
			A[i].idx = i;
		}
		sort(A + 1, A + N + 1, cmp_val);
		for(int i = 1; i <= N; i++) {
			if(i <= N / 2) {
				A[i].ans = A[N / 2 + 1].val;
			}
			else {
				A[i].ans = A[N / 2].val;
			}
		}
		sort(A + 1, A + N + 1, cmp_idx);
		for(int i = 1; i <= N; i++)
			printf("%d\n", A[i].ans);
	}
	return 0;
}