#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f[3009],dp[3002][3002],z,x;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a;
	for(b=1; b<=a; b++){
		cin>>f[b];
	}
	for(b=1; b<=a; b++){
		for(c=1; c<=a-b+1; c++){
			if(b==1){
				if((a-b)%2==0) dp[c][c+b-1]=f[c]; else dp[c][c+b-1]=-f[c];
			}else{
				if((a-b)%2==0) z=f[c]; else z=-f[c];
				if((a-b)%2==0) x=f[c+b-1]; else x=-f[c+b-1];
				dp[c][c+b-1]=z+dp[c+1][c+b-1];
				if((a-b)%2==0) dp[c][c+b-1]=max(dp[c][c+b-1],x+dp[c][c+b-2]); else dp[c][c+b-1]=min(dp[c][c+b-1],x+dp[c][c+b-2]);
			}
		}
	}
	cout<<dp[1][a];
	return 0;
} 