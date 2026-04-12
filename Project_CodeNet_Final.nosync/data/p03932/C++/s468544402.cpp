#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
#include "tuple"

#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int h, w, a[200][200], dp[200][200][400] = {};
int main() {
	cin >> h >> w;
	rep(h)
		REP(w, j)
			cin >> a[i][j];
	for (int i = 1; i != w + h - 2; ++i) {
		for (int j = max(0, i - h + 1); j != min(w, i + 1); ++j) {
			for (int k = j + 1; k != min(w, i + 1); ++k) {
				dp[j][k][i] = a[i - j][j] + a[i - k][k];
				if (j)
					dp[j][k][i] += max({ dp[j - 1][k - 1][i - 1],dp[j - 1][k][i - 1],dp[j][k - 1][i - 1],dp[j][k][i - 1] });
				else
					dp[j][k][i] += max(dp[j][k - 1][i - 1], dp[j][k][i - 1]);
			}
		}
	}
	cout << a[0][0] + a[h - 1][w - 1] + dp[w - 2][w - 1][w + h - 3] << endl;
	return 0;
}
