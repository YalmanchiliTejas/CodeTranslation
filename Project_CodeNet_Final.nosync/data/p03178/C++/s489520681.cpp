#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

long long dp[128][10100];
string s;
int n;
long long ans;

int main(){
	cin>>s>>n;
	for(int i=0;i<=9;i++) dp[i%n][1]++;
	dp[0][0]=1;
	int l=s.size();
	for(int i=2;i<l;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<=9;++k){
				dp[j][i]+=dp[(9*n+j-k)%n][i-1];
			}
			dp[j][i]%=mod;
		}
	}
	ans=(mod-1+dp[0][l-1])%mod;
	int cnt=0;
	for(int j=1;j<=s[0]-'0';++j) ans+=dp[(9*n-j)%n][l-1],ans%=mod;
	for(int i=l;i>=2;--i){
		cnt+=s[l-i]-'0';
		for(int j=s[l-i+1]-'0'+1;j<=9;++j)
		ans+=(mod-dp[((cnt+9)*n-cnt-j)%n][i-2]),ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}