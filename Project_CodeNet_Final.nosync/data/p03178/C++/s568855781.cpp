#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long ans, DP[10005][105][2];
string k;
int d,n;

long long dp(int pos, int remain, bool full){
//	printf(">> %d %d\n",pos,remain);
	if(pos>=n){
		if(remain == 0) return 1;
		return 0;
	}
	long long res = 0;
	if(DP[pos][remain][full]!=-1) return DP[pos][remain][full];
	if(full){
		for(int i=0;i<k[pos]-'0';i++){
			res += dp(pos+1,(remain+i)%d,0);
			res %=MOD;
		}
		res += dp(pos+1,(remain+k[pos]-'0')%d,1);
		res%=MOD;
	} else {
		for(int i=0;i<=9;i++){
			res += dp(pos+1,(remain+i)%d,0);
			res %=MOD;
		}
	}
	res %=MOD;
//	printf("%d %d = %lld\n",pos,remain,res);
	return DP[pos][remain][full] = res;
}

int main(){
	memset(DP,-1,sizeof DP);
	cin>>k;
	n = k.length();
	scanf("%d",&d);	
	ans = dp(0,0,1);
	printf("%lld\n",(ans-1+MOD)%MOD);
	return 0;
}