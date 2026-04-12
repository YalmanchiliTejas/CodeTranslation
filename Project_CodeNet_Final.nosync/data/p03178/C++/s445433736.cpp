#include <bits/stdc++.h>
using namespace std;

char k[10005];
int l;
int d;
long long M=1000000007;
long long memo[10005][105][2];

long long dp(int i,int mod,int flag){
	if(i==l){
		if(mod==0)return 1;
		return 0;
	}
	if(memo[i][mod][flag]!=-1)return memo[i][mod][flag];
	if(flag==0){
		long long ans=0;
		for(int j=0;j<=9;j++){
			ans+=dp(i+1,(mod+j)%d,0);
			ans%=M;
		}
		return memo[i][mod][flag]=ans;
	}else{
		long long ans=0;
		int x=k[i]-'0';
		for(int j=0;j<x;j++){
			ans+=dp(i+1,(mod+j)%d,0);
			ans%=M;
		}
		ans+=dp(i+1,(mod+x)%d,1);
		ans%=M;
		return memo[i][mod][flag]=ans;
	}
}

int main(){
	scanf("%s %d",k,&d);
	l=strlen(k);
	memset(memo,-1,sizeof(memo));
	printf("%lld",(dp(0,0,1)-1+M)%M);
}