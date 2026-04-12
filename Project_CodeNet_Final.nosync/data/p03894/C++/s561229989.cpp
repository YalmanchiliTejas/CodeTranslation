#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int N; int Q;
	while(~scanf("%d%d", &N, &Q)) {
		vector<int> A(Q);
		vector<int> B(Q);
		for(int i = 0; i < Q; ++ i)
			scanf("%d%d", &A[i], &B[i]), -- A[i], -- B[i];
		vector<int> iperm(N);
		iota(iperm.begin(), iperm.end(), 0);
		for(int i = Q - 1; i >= 0; -- i)
			swap(iperm[A[i]], iperm[B[i]]);
		int pos = 0;
		vector<bool> possible(N);
		rer(i, 0, Q) {
			if(pos > 0)
				possible[iperm[pos - 1]] = true;
			if(pos < N - 1)
				possible[iperm[pos + 1]] = true;
			if(i < Q) {
				if(pos == A[i]) pos = B[i];
				else if(pos == B[i]) pos = A[i];
				swap(iperm[A[i]], iperm[B[i]]);
			}
		}
		possible[pos] = true;
		int ans = (int)count(possible.begin(), possible.end(), true);
		printf("%d\n", ans);
	}
	return 0;
}
