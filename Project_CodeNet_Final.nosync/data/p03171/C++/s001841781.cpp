//Fat Elephant!!!!
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n;
int a[3003];
ll dp[3003][3003];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int l=n;l>=1;l--)
		for(int r=l;r<=n;r++){
			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		}
	printf("%lld\n",dp[1][n]);
	ll ans=0;
	return 0;
}