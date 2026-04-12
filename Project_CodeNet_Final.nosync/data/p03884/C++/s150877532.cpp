#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 100000000000007LL
#define ll long long
using namespace std;
ll dp[610][9],sum[610];
ll amari[610];
signed main(){
	int k;
	cin>>k;
	for(int i=1;i<=8;i++){
		dp[1][i]=1;
	}
	for(int i=2;i<=600;i++){
		dp[i][1] = 1;
		for(int j=2;j<=8;j++){
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
		}
	}
	/* for(int i=1;i<=20;i++){
		cout<<i<<": ";
		for(int j=1;j<=8;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	} */
	sum[1] = dp[1][8];
	for(int i=2;i<=600;i++){
		sum[i] = sum[i-1] + dp[i][8];
	}
	string str;
	int start = 1;
	for(int i=1;i<=600;i++){
		if(sum[i] <= k)start = i;
	}
	k = k - sum[start];
	for(int i=start;i>=1;i--){
		amari[i] = k / dp[i][8];
		k %= dp[i][8];
		//cout<< amari[i] << " "<< k << endl;
	}
	for(int i=start;i>=1;i--){
		for(int j=0;j<amari[i];j++){
			str += 'F';
		}
		str += "FESTIVAL";
	}
	cout<<str<<endl;
	return 0;
}