#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>


using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

#define ARRAY_MAX 3005

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

ll dp[ARRAY_MAX][ARRAY_MAX];

int main() {

	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i <= n; i++)
	{
		dp[i][i] = 0;
	}

	for (int len = 1; len <= n; len++)
	{
		//区間の長さがlenの時
		for (int i = 0; i + len <= n; i++)
		{
			//区間の左端がiから長さlenの区間を見る
			int j = i + len;//[i,j)

			if ((n - len) % 2 == 0)
			{
				//先手
				//a[i]を取るかa[j-1]を取るか
				dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j-1]);
				
			}
			else
			{
				//後手
				//a[i]を取るかa[j-1]を取るか
				dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j-1]);
			}
		}
	}

	cout << dp[0][n] << endl;

	return 0;
}