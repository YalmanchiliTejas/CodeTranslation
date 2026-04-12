#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, k;
//int dp[200 + 10][100 + 10][1 << (10 + 1)];
//集合は、直近k+1個の数字を上(=1)or下(=0)においたときのbit集合

int m = 1000000007;

int cnt[30];

unsigned long long popcount(unsigned long long x) {
	x = ((x & 0xaaaaaaaaaaaaaaaaUL) >> 1) +
		(x & 0x5555555555555555UL);
	x = ((x & 0xccccccccccccccccUL) >> 2) +
		(x & 0x3333333333333333UL);
	x = ((x & 0xf0f0f0f0f0f0f0f0UL) >> 4) +
		(x & 0x0f0f0f0f0f0f0f0fUL);
	x = ((x & 0xff00ff00ff00ff00UL) >> 8) +
		(x & 0x00ff00ff00ff00ffUL);
	x = ((x & 0xffff0000ffff0000UL) >> 16) +
		(x & 0x0000ffff0000ffffUL);
	x = ((x & 0xffffffff00000000UL) >> 32) +
		(x & 0x00000000ffffffffUL);
	return x;
}

int main() {
	cin >> N >> k >> m;
	
	vector<vector<vector<int>>> dp(2 * N + 1, vector<vector<int>>(N + 1, vector<int>((1 << (k + 1)), 0)));
	dp[0][0][0] = 1;
	for (int i = 0; i < 2 * N; i++) {
		for (int j = (i + 1) / 2; j <= N; j++) {
			for (int bit = 0; bit < (1 << (k + 1)); bit++) {
				if (dp[i][j][bit] == 0)continue;

				//cout << i << " " << j << " " << bit << " " << dp[i][j][bit] << endl;	

				//今のメモした桁数。
				int keta = min(k + 1, i);
				if (keta == 0) {
					//i == 0, j == 0, bit == 0の時
					dp[i + 1][j + 1][1] = dp[i][j][bit];
					continue;
				}

				vector<int> ue;
				int shita = 0;
				for (int l = i; l >= i - keta + 1; l--) {
					if ((bit >> (i - l)) & 1) {
						//数字lを上に置いたとき
						ue.push_back(l);
					}
					else if (shita == 0) {
						shita = l;
					}
				}
				//下の制約がないとき
				if (shita == 0) {
					shita = i + 1;
				}

				int cpy = bit;
				//下に置く
				//j - (i - j) - 1がout of rangeする！
				if (i != 2 * j &&
					(abs(shita - (i + 1)) <= k
						&& abs(ue.at(j - (i - j) - 1) - (i + 1)) <= k)) {
					cpy = ((cpy << 1) & ((1 << (k + 1)) - 1));
					dp[i + 1][j][cpy] += dp[i][j][bit];
					dp[i + 1][j][cpy] %= m;
				}

				cpy = bit;
				//cout << i << " " << j << " " << bit << "A" << " " << ue.size() << endl;

				//cout << "ue == " << endl;
				//for (int i = 0; i < ue.size(); i++)cout << ue[i] << " ";
				//cout << endl;

				//条件が少しおかしいと思う
				//上に置く
				if ((j * 2 == i && abs(ue.front() - (i + 1)) <= k)|| 
					((j * 2 != i) && (i + 2 - shita <= k) && (i + 2 - ue.at(j - (i - j) - 1) <= k) && 
					abs(ue.front() - (i + 1)) <= k && j != N)) {
					cpy = ((cpy << 1) & ((1 << (k + 1)) - 1));
					cpy += (1 << 0);
					dp[i + 1][j + 1][cpy] += dp[i][j][bit];
					dp[i + 1][j + 1][cpy] %= m;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << (k + 1)); i++) {
		ans += dp[2 * N][N][i];
		ans %= m;
	}
	cout << ans << endl;
	return 0;
}
