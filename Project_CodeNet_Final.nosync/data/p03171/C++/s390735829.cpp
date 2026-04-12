#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll dp[3010][3010];
int n,a[3010];
int main() {
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",a+i);
	}
	int j,k;
	for(k=1;k<=n;k++) {
		for(i=0;i+k-1<n;i++) {
			j=i+k-1;
			bool fir=n%2==k%2;
			if(k==1) {
				if(fir) dp[i][j]=a[i];
				else dp[i][j]=-a[i];
			} else {
				if(fir) dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
				else dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
			}
		}
	}
	printf("%lld",dp[0][n-1]);
	return 0;
}