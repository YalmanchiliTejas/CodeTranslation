#include<iostream>
#define int long long
using namespace std;
const int N=2e5+2;
const int mod=1e9+7;
int dp[N],sum[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,max1,ans=0,m;
	string s;
	cin>>n>>m>>s;
	if(s[0]=='B'){
		for(i=0;i<m;i++){
			if(s[i]=='B'){
				s[i]='R';
			}
			else{
				s[i]='B';
			}
		}
//		cout<<s<<endl;
	}
	bool cac=true;
	for(i=1;i<m;i++){
		if(s[i]!=s[i-1]){
			cac=false;
			break;
		}
	}
	if(cac){
//		cout<<0<<endl;
		dp[0]=1;
		sum[0]=1;
		ans=1;
		for(i=1;i<=n;i++){
			if(i!=1){
				dp[i]=sum[i-2];
			}
			sum[i]=sum[i-1]+dp[i];
			if(sum[i]>=mod){
				sum[i]-=mod;
			}
		}
		for(i=1;i<=n-1;i++){
			ans+=(i+1)*dp[n-i-1];
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		if(n&1){
			cout<<0;
			return 0;
		}
		max1=n-1;
		cac=true;
		j=1;
		for(i=1;i<m;i++){
			if(s[i]==s[i-1]){
				j++;
			}
			else{
				if(s[i]=='B'){
					if(cac){
						if(j&1){
							max1=min(max1,j);
						}
						else{
							max1=min(max1,j+1);
						}
						cac=false;
					}
					else{
						if(j&1){
							max1=min(max1,j);
						}
					}
				}
				j=1;
			}
		}
		dp[0]=1;
		sum[0]=1;
		for(i=1;i<=n;i++){
			sum[i]=sum[i-1];
			if(i&1){
				continue;
			}
			dp[i]=sum[i-2];
			if(i-max1-2>=0){
				dp[i]-=sum[i-max1-2];
				if(dp[i]<0){
					dp[i]+=mod;
				}
			}
			sum[i]+=dp[i];
			if(sum[i]>=mod){
				sum[i]-=mod;
			}
		}
		for(i=1;i<=max1;i+=2){	
			ans+=(i+1)*dp[n-i-1];
			ans%=mod;
		}
		cout<<ans;
	}
}