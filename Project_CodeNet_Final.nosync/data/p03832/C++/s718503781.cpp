#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int inf = 1e9;
const ll linf = 1LL << 50;
const int mod = 1e9 + 7;
int n, a, b, c, d;
int dp[1002][1002];
int lad[1002];
int ilad[1002];

int main(int argc, char const* argv[])
{
	cin >> n >> a >> b >> c >> d;
	lad[0] = 1;
	for(int i = 1; i <= n; i++){
			lad[i] = ((ll)lad[i - 1] * i) % mod;
	}
	int tmp = mod - 2;
	int pmp = lad[n];
	ilad[n] = 1;
	while(tmp > 0){
			if((tmp & 1) == 1)ilad[n] = (ll)ilad[n] * pmp % mod;
			pmp = pmp * (ll)pmp % mod;
			tmp = tmp >> 1;
	}
	ilad[0] = 1;
	for(int i = n - 1; i > 0; i--){
			ilad[i] = (ll)ilad[i+1] * (i + 1) % mod;
	}
	dp[a][0] = 1;
	for(int i = a; i < b+1; i++){
			for(int j = 0;j <= n; j++){
					dp[i+1][j] = dp[i][j];
					for(int k = c; k <= min(j / i, d); k++){
							int ttmp = (dp[i][j - k * i] * (ll)lad[n - j + k * i]) % mod;
							ttmp = ((ll)ttmp * ilad[n - j]) % mod;
							ttmp = ((ll)ttmp * ilad[k]) % mod;
							for(int l = 0; l < k; l++){
									ttmp = ((ll)ttmp * ilad[i]) % mod;
							}
							dp[i+1][j] = ((ll)dp[i+1][j] + ttmp) % mod;
					}
			}
	}
	cout << dp[b+1][n] << endl;
	return 0;
}
