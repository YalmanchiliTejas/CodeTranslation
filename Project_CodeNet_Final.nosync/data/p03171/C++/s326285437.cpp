  //                                                   ¯\_(ツ)_/¯
  //#pragma GCC optimize("Ofast")
 //#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
#define pi pair<int,int>
const int N=1e6+5,MOD=1e9+7;

using namespace std;

int n;
ll dp[3005][3005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	scanf("%d",&n);

	std::vector<int> a(n+1);

	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	for(int l=n;l>=1;l--){

		for(int r=l;r<=n;r++){
			if((l-1+n-r)%2==0)
				dp[l][r]=max(a[l]+dp[l+1][r],a[r]+dp[l][r-1]);
			else
				dp[l][r]=min(-a[l]+dp[l+1][r],-a[r]+dp[l][r-1]);
		}
	}

	printf("%lld\n",dp[1][n] );

}