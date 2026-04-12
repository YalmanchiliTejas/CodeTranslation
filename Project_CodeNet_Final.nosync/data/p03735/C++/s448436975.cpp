#include <bits/stdc++.h>
#define INF (0x3f3f3f3f)
using namespace std;
typedef long long ll;

const int MAXN = 200055;

int C[MAXN], Cn;

int O[MAXN*2];
int A[MAXN], B[MAXN];

ll Ans;
int N, L = INF, mxA, mxB, mnA, mnB;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		if(A[i] > B[i]) swap(A[i], B[i]);
	}
	Ans = ll((mxA = *max_element(A, A+N)) - (mnA = *min_element(A, A+N)));
	Ans *= ll((mxB = *max_element(B, B+N)) - (mnB = *min_element(B, B+N)));

	iota(O, O+(N<<1), 0); sort(O, O+(N<<1), [&](int a, int b) {
		return ((a&1) ? A : B)[a>>1] < ((b&1) ? A : B)[b>>1];
	});

	for(int s = 0, e = -1, x, l; s <= N; s++) {
		for(; e+1 < (N<<1) && Cn < N;) {
			e++;
			x = O[e] >> 1;
			if(!C[x]) Cn++;
			C[x]++;
		}
		if(Cn < N) break;
		x = O[s];
		l = -((x&1) ? A : B)[x>>1];
		x = O[e];
		l += ((x&1) ? A : B)[x>>1];
		if(l < L) L = l;
		x = O[s] >> 1;
		C[x]--;
		if(!C[x]) Cn--;
	}

	cout << min(Ans, ll(L) * (max(mxA, mxB) - min(mnA, mnB))) << endl;
	return 0;
}