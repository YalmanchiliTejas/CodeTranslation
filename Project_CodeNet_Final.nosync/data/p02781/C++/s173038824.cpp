#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define mrep(i,from,n) for(int i = from; i < n; i++)
#define mreps(i,from,n) for(int i = from; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())
typedef long long ll;
typedef pair<ll, ll> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll mod = 1000000007;

void solve()
{
	string n; cin >> n;
	int k; cin >> k;
	int m=sz(n);
	//dp[i+1][smaller][j]:i桁目までで0以外の数がj個あるものの数
	int dp[105][2][5]={};
	dp[0][0][0]=1;
	rep(i,m)
	{
		rep(j,k+1)
		{
			if(n[i]=='0')
			{
				dp[i+1][0][j]+=dp[i][0][j];
				dp[i+1][1][j]+=dp[i][1][j];
				if(j>0)dp[i+1][1][j]+=dp[i][1][j-1]*9;
			}
			else
			{
				if(j>0)dp[i+1][0][j]+=dp[i][0][j-1];
				dp[i+1][1][j]+=dp[i][0][j]+dp[i][1][j];
				if(j>0)dp[i+1][1][j]+=dp[i][1][j-1]*9+dp[i][0][j-1]*((n[i]-'0')-1);
			}
		}
	}
	int ans = dp[m][0][k]+dp[m][1][k];
	cout << ans << endl;
	return;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
