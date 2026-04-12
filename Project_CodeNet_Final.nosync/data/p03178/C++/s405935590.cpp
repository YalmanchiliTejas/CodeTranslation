#include <bits/stdc++.h>
using namespace std;



int main() {
    
	string s;
	long long d;
	cin>>s>>d;
	long long dp[s.size()+1][d][2];
	memset(dp,0,sizeof(dp));
	dp[0][0][1]=1;
	for(long long i=1;i<=s.size();i++){
	    for(long long j=0;j<d;j++){
            for(long long k=0;k<=1;k++){
                for(long long l=0;l<=(k?s[i-1]-'0':9);l++){
                    dp[i][(j+l)%d][k&(l==s[i-1]-'0')]=(dp[i][(j+l)%d][k&(l==s[i-1]-'0')]+dp[i-1][j][k])%1000000007;
              
                   
                }
            }
	    }
	}
/*	for(long long i=1;i<=s.size();i++){
	    for(long long k=0;k<=1;k++){
            for(long long j=0;j<d;j++){
                for(long long l=0;l<=(k? 9:s[i-1]-'0');l++){
                    dp[i][k | (l<s[i-1]-'0')][(j+l)%d]=(dp[i][k | (l<s[i-1]-'0')][(j+l)%d]+dp[i-1][k][j])%1000000007;
              
                   
                }
            }
	    }
	}*/
	cout<<(dp[s.size()][0][0]+dp[s.size()][0][1]-1+1000000007)%1000000007;
	
}
