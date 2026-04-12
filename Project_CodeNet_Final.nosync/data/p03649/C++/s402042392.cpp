#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int N;
	while (~scanf("%d", &N)) {
		vector<long long> A(N);
		for (int i = 0; i < N; ++ i)
			scanf("%lld", &A[i]);
		ll ans = 0;
		for (int n = 1; n <= N; ++ n) {
			sort(A.begin(), A.end());
			ll cycles = max(0LL, n == N ?
				A[0] - N :
				(A[N - n] - A[N - n - 1]) / (N + 1));
			reu(i, N - n, N)
				A[i] -= cycles * (N + 1 - n);
			rep(i, N - n)
				A[i] += cycles * n;
			ans += cycles * n;
			while (1) {
				sort(A.begin(), A.end());
				if (A[N - 1] - (n == N ? 0 : A[N - n - 1]) < N) break;
				rep(i, N - 1)
					A[i] += 1;
				A[N - 1] -= N;
				++ ans;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
