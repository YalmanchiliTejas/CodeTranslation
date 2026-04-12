#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int N, a[3000];
ll DP[3001][3001], res;

int main() {
	cin >> N;
	for (int i = 0; i != N; ++i)
		cin >> a[i];
	for (int i = 1; i != N + 1; ++i) {
		for (int j = 0; i + j != N + 1; ++j) {
			if ((N - i) & 1)
				DP[j][i + j] = min(DP[j][i + j - 1] - a[i + j - 1], DP[j + 1][i + j] - a[j]);
			else
				DP[j][i + j] = max(DP[j][i + j - 1] + a[i + j - 1], DP[j + 1][i + j] + a[j]);
//			cout << j << sp << i + j << sp << DP[j][i + j] << endl;
		}
	}
	cout << DP[0][N] << endl;
}