#include "iostream"
#include "random"
#include "string"
#include "bitset"
#include "algorithm"
#include "map"
#include "queue"
#include "list"
#include "set"
#include "climits"

using namespace std;

map<string, long long> idx;
long long weight[7];
long long market[7];
long long price[7][7];
long long x[7];
long long y[7];
long long tsp[1 << 7];
long long dp1[8][100001];
long long dp2[(1 << 7) + 1][100001];
long long money[1 << 7];
signed main() {
	long long N, M, W, T;
	cin >> N >> M >> W >> T;
	for (long long i = 0; i < M; i++) {
		string S;
		cin >> S >> weight[i] >> market[i];
		idx[S] = i;
	}
	fill((long long*)price, (long long*)(price + 7), 1 << 30);
	for (long long i = 0; i < N; i++) {
		long long L;
		cin >> L;
		cin >> x[i] >> y[i];
		for (long long j = 0; j < L; j++) {
			string R;
			long long Q;
			cin >> R >> Q;
			price[i][idx[R]] = min(price[i][idx[R]], Q);
		}
	}
	for (long long bit = 1; bit < (1 << N); bit++) {
		long long perm[7] = { 0 };
		long long n = 0;
		for (long long i = 0; i < N; i++) {
			if (bit&(1 << i)) perm[n++] = i;
		}
		tsp[bit] = 1 << 30;
		do {
			long long sum = 0;
			long long prev_x = 0;
			long long prev_y = 0;
			for (long long i = 0; i < n; i++) {
				sum += abs(x[perm[i]] - prev_x);
				sum += abs(y[perm[i]] - prev_y);
				prev_x = x[perm[i]];
				prev_y = y[perm[i]];
			}
			sum += abs(prev_x);
			sum += abs(prev_y);
			tsp[bit] = min(tsp[bit], sum);
		} while (next_permutation(perm, perm + n));
	}
	for (long long bit = 1; bit < (1 << N); bit++) {
		long long min_price[7];
		fill(min_price, min_price + 7, 1 << 30);
		for (long long i = 0; i < N; i++) {
			if (!(bit&(1 << i))) continue;
			for (long long j = 0; j < M; j++) {
				min_price[j] = min(min_price[j], price[i][j]);
			}
		}
		long long w[7], v[7];
		long long cnt = 0;
		for (long long i = 0; i < M; i++) {
			if (min_price[i] <= market[i]) {
				w[cnt] = weight[i];
				v[cnt] = market[i] - min_price[i];
				cnt++;
			}
		}
		fill((long long*)dp1, (long long*)(dp1 + 8), 0);
		for (long long i = 0; i < cnt; i++) {
			for (long long j = 0; j <= W; j++) {
				if (j >= w[i]) dp1[i + 1][j] = max(dp1[i][j], dp1[i + 1][j - w[i]] + v[i]);
				dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
			}
		}
		money[bit] = dp1[cnt][W];
	}
	for (long long i = 0; i < (1 << N); i++) {
		for (long long j = 0; j <= T; j++) {
			if (j >= tsp[i]) dp2[i + 1][j] = max(dp2[i][j], dp2[i + 1][j - tsp[i]] + money[i]);
			dp2[i + 1][j] = max(dp2[i + 1][j], dp2[i][j]);
		}
	}
	cout << dp2[1 << N][T] << endl;
	return 0;
}
