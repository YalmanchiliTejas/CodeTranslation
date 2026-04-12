# pragma GCC optimize("O3")
# include <bits/stdc++.h>
std::pair<int,int> DR[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define rc(s) return cout << s,0
# define rcg(s) cout << s;exit(0)
# define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define db(x) cerr << #x << " = " << x << '\n'
# define pb push_back
# define mp make_pair
# define all(s) s.begin(),s.end()
# define sz(x) (int)((x).size())
# define int ll
using namespace std;

int n,a[3005],dp[3005][3005][2];

int32_t main(){_
    //freopen("in","r",stdin);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = n;i >= 1;i--)
	{
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
		for(int j = i + 1;j <= n;j++)
		{
			dp[i][j][0] = max(a[i] + dp[i + 1][j][1],a[j] + dp[i][j - 1][1]);
			dp[i][j][1] = min(-a[i] + dp[i + 1][j][0],-a[j] + dp[i][j - 1][0]);
		}
	}
	rc(dp[1][n][0]);
}