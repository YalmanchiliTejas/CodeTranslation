#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long int llint;
string k;
llint d;
llint dp[10005][105][2];
llint sum2(llint a,llint b) {
	return ((a%1000000007)+(b%1000000007))%1000000007;
}
llint rek(llint ind,llint sum,llint tight) {
	if(ind>=k.size()) return llint(sum==0);
	if(dp[ind][sum][tight]!=-1) return dp[ind][sum][tight];
	llint ret=0;
	llint x=9;
	if(tight==1) x=int(k[ind])-48;
	for(llint i=0;i<=x;i++) {
		if(i<x) ret=sum2(ret,rek(ind+1,(sum+i)%d,0));
		else ret=sum2(ret,rek(ind+1,(sum+i)%d,tight));
	}
	if(tight==0) dp[ind][sum][tight]=ret;
	//cout <<ind<<" "<<sum<<" "<<tight<<" "<<ret<<endl;
	return ret;
}
int main()
{
	cin >> k >> d;
	memset(dp,-1,sizeof(dp));
	cout <<(rek(0,0,1)-1+1000000007)%1000000007;
	/*for(int i=0;i<k.size();i++) {
		for(int j=0;j<20;j++) {
			cout <<dp[i][j][1]<<" ";
		}
		cout <<endl;
	}*/
	return 0;
}
