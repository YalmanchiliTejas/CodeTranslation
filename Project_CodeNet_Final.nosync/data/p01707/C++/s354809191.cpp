#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll d;
int n,x;
ll dp[2001][2001];

long long ex(long long a,long long e){
	if(e==0) return 1;
	long long tmp=ex(a,e/2);
	tmp*=tmp;
	tmp%=mod;
	if(e%2==1) tmp*=a;
	tmp%=mod;
	return tmp;
}

long long inv(long long a){
	return ex(a,mod-2);
}

int main(){
	while(true){
		cin>>n>>d>>x;
		if(n==0) break;
		dp[0][0]=1;
		rep1(i,min(d,(ll)n)){
			rep1(j,n){
				dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
				if(j-x>=0) dp[i][j]-=dp[i-1][j-x];
				dp[i][j]=(dp[i][j]+mod)%mod;
			}
		}
		ll c=1,ans=0;
		rep(i,min((ll)n,d)+1){
			ans+=dp[i][n]*c;
			ans%=mod;
			c=c*((d-i)%mod)%mod*inv(i+1)%mod;
			c%=mod;
		}
		cout<<ans<<endl;
	}
}