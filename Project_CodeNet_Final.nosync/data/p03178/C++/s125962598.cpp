#include <bits/stdc++.h>
using namespace std;
long long P=1000000007;
long long dp[10009][105][2];
long long dig(int i,int r,int f,string &k,int d){
	if(i==k.size()){
		if(r%d==0)
			dp[i][r][f]=1;
		else
			dp[i][r][f]=0;
	}
	if(dp[i][r][f]==-1){
		long long sum=0;
		if(f==1){
			int j=0;
			for(j=0;j<(k[i]-'0');j++)
				sum=(sum+dig(i+1,(r-j+d)%d,0,k,d))%P;
			sum=(sum+dig(i+1,(r-j+d)%d,1,k,d))%P;
		}
		else{
			int j;
			for(j=0;j<10;j++)
				sum=(sum+dig(i+1,(r-j+d)%d,0,k,d))%P;
		}
		dp[i][r][f]=sum;
	}
	return dp[i][r][f];
}
int main(){
	string k;
	int d;
	cin >> k;
	cin >> d;
	memset(dp,-1,sizeof(long long)*10009*105*2);
	cout << (dig(0,0,1,k,d)-1+P)%P << endl;
}