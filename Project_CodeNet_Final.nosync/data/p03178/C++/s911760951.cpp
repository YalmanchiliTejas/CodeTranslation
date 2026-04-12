// fest
#include <bits/stdc++.h>	

#define pb push_back
#define F first
#define S second
#define y1 dasdasfasfas
#define x1 wqdadfasfasfas
#define All(c) c.begin(), c.end()
#define SZ(A) (int((A).size()))
#define umap unordered_map
#define __ fflush(stdout)
#define FILENAME ""

typedef long long ll;
typedef long double ld;    

using namespace std;

void FREOPEN() {
	#ifdef LOCAL
		freopen(".in", "r", stdin);
		freopen("1.out", "w", stdout);
	#else
		//freopen(FILENAME".in", "r", stdin);
		//freopen(FILENAME".out", "w", stdout);
	#endif
}

inline double Time() {return (clock() * 1.0) / CLOCKS_PER_SEC; }             

const int N = 20500, inf = 1e9 * 2;

const ll MOD = 1e9 + 7ll, INF = 1e18;

const int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};

string get_string() {
	string ret = "";
	char c;
	while ((c = getchar()) != '\n') ret += c;
	return ret;
}

int dp[N][100][2];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	FREOPEN();
	string num = get_string();
	int d;
	scanf("%d ", &d);
	num = '$' + num;
	int n = SZ(num) - 1;
	dp[0][0][1] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			for (int k = 0; k < (int)(num[i + 1] - '0'); k++) {
				add(dp[i + 1][(j + k) % d][0], dp[i][j][1]);
			}
			add(dp[i + 1][(j + (int)(num[i + 1] - '0')) % d][1], dp[i][j][1]);
			for (int k = 0; k < 10; k++) {
				add(dp[i + 1][(j + k) % d][0], dp[i][j][0]);
			}
		}
	}
	add(dp[n][0][1], dp[n][0][0]);
	printf("%d", (dp[n][0][1] + MOD - 1) % MOD);
	return 0;
}
