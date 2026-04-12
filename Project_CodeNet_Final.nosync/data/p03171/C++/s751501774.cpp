#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9 + 5;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

const int mxs = 3002;
int main()
{
	ll dp[mxs][mxs] = {}, in[mxs] ;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> in[i];
		dp[i][i] = in[i];
	}
	for(int l = n - 1; l >= 0; l--)
		for(int r = l; r < n; r++)
		{
			if(l < r)
			{
				dp[l][r] = max(in[l] - dp[l + 1][r], in[r] - dp[l][r - 1]);
			}
		}
	cout << dp[0][n - 1] << '\n';
}
