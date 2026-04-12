#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll dp[3005][3005],arr[3005];

int main()
{jizz
	ll n;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i],dp[i][i]=arr[i],arr[i]+=arr[i-1];
	for(int i=1;i<n;++i)
		for(int j=1;j+i<=n;++j)
			dp[j][j+i]=arr[j+i]-arr[j-1]-min(dp[j+1][j+i],dp[j][j+i-1]);
	cout << 2*dp[1][n]-arr[n] << "\n";
}