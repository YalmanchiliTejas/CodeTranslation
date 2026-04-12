#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int d;
char c[10005];
const int mod=1e9+7;
int main() {
	scanf("%s %d",c,&d);
	int len=strlen(c);
	vector<vector<int>>dp(d,vector<int>(2));
	dp[0][0]=1;
	for(int index=0;index<len;index+=1){
	    vector<vector<int>>ndp(d,vector<int>(2));
	    for(int sum=0;sum<d;sum+=1){
	        for(bool in:{0,1}){
	            for(int bit=0;bit<10;bit+=1){
	                if(bit>c[index]-'0'&&!in){
	                    break;
	                }
	                ndp[(sum+bit)%d][(in)||(bit<c[index]-'0')]=(ndp[(sum+bit)%d][(in)||(bit<c[index]-'0')]+dp[sum][in])%mod;
	            }
	        }
	    }
	    dp=ndp;
	}
	int ans=(dp[0][0]+dp[0][1])%mod;
	ans-=1;
	if(ans==-1){
	    ans=mod-1;
	}
	printf("%d",ans);
	return 0;
}