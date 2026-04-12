#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define zeroend __builtin_ctz
#define ones __builtin_popcount
#define ends "\n"
#define space ' '
typedef long long ll;
typedef pair<int, int> pii;

/*
void solve(int i, int j, string s){
	if(i==0)
		ans.insert(s2.substr(0, j)+s);
	else if(j==0)
		ans.insert(s1.substr(0, i)+s);
	else if(s1[i-1]==s2[j-1])
		solve(i-1, j-1, s1[i-1]+s);
	else{
		if(dp[i-1][j]<=dp[i][j-1])
			solve(i-1, j, s1[i-1]+s);
		if(dp[i-1][j]>=dp[i][j-1])
			solve(i, j-1, s2[j-1]+s);
	}
}*/


/*
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	for(int i=1; i<n; ++i){
		for(int j=0; j<i; ++j){
			if(a[j]>a[i]&&low[i]<high[j]+1)
				low[i]=high[j]+1;
			else if(a[j]<a[i]&&high[i]<low[j]+1)
				high[i]=low[j]+1;
		}
		ans=max({ans, low[i], high[i]});
	}

	cout << ans << ends;


*/

const int N = 3000, M = 1e9+7;

ll dp[N+1][N+1];
//array<ll, 3> dp;
//set<string> ans;
//vector<int> low(N, 1), high(N, 1);
ll a[N];

int n, m;

int main(){
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	for(int i=n-1; i>=0; --i)
		for(int j=i; j<=n-1; ++j)
			if(i==j) dp[i][j]=a[i];
			else dp[i][j]=max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
		
	cout << dp[0][n-1] << ends;

}