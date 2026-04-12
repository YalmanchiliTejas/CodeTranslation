#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector <int>
#define vl vector <ll>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d",x)
#define plld(x) printf("%lld",x)
#define pds(x) printf("%d ",x)
#define pllds(x) printf("%lld ",x)
#define pdn(x) printf("%d\n",x)
#define plldn(x) printf("%lld\n",x)
#define INF 2e9
#define INFLL 4e18
using namespace std;
ll powmod(ll base,ll exponent,ll mod){ // with mod < 1e9
	ll ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base)%mod;
		base=(base*base)%mod;
		exponent/=2;
	}
	return ans;
}
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
const int upperlimit = 1e6+1;
const int mod = 1e9+7;
ll dp[upperlimit][3];
int arr[upperlimit];
int main() {
	int n,num;
	sd(n);
	ll ans=-INFLL;
	num=n/2;
	for(int i = 1; i <= n; i++) sd(arr[i]);
	for(int i = 0; i <= n; i++) for(int j = 0; j < 3; j++) dp[i][j]=-INFLL;
	dp[0][0]=0;dp[1][0]=arr[1];dp[2][0]=arr[2];
	for(int i = 3; i <= n; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k <= j; k++){
				if(i-k<2) break;
				dp[i][j]=max(dp[i][j],dp[i-k-2][j-k]+arr[i]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++){
			if(int((i+1-j)/2)==num){
				ans=max(ans,dp[i][j]);
			}
		}
	}
	plld(ans);
	return 0;
}