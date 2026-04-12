#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007 
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int n,x,m;
	cin >> n >> x >> m;
	int dp[2][m+1];
	memset(dp,0,sizeof(dp));
	dp[0][x]=0;
	dp[1][x]=1;
	int sum=x,lst=x;
	for(int i=2;i<=n;i++){
		int num=lst*lst;
		if(num==0){
			cout << sum << endl;
			exit(0);
		}
		int temp=num-(num/m)*m;
		if(dp[0][temp]!=0){
			int ans=0;
			ans+=sum;
			int val=sum-dp[0][temp];
			ans+=((n-i+1)/(i-dp[1][temp]))*val;
			int lft=n-i+1-((n-i+1)/(i-dp[1][temp]))*(i-dp[1][temp]);
			while(lft--){
				num=lst*lst;
				temp=num-(num/m)*m;
				ans+=temp;
				lst=temp;
			}
			cout << ans << endl;
			exit(0);
		}
		else{
			dp[0][temp]=sum;
			dp[1][temp]=i;
			sum+=temp;
			lst=temp;
		}
	}
	cout << sum << endl;
}
