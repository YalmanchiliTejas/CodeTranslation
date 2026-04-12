#include <bits/stdc++.h>
using namespace std;
 
 string arr;
 const int  mod = 1e9+7;
long long dp[10005][101][2];
 
int d;
 
long long back(int in, long sum, bool flag  ){
	
 	if(in> arr.size()) {  if(sum%d==0) return 1; else return 0; }
 	
 	if(dp[in][sum][flag]!=-1)	return dp[in][sum][flag];
 	
 	 int limit = 9;
 	 if(!flag) limit=  arr[in-1]-'0';
 	
	long long res=0;
	
 	for(int i=0; i<=limit; ++i){
 	res+= (back(in+1, (sum+i)%d , flag || i<limit)%mod);		
 	res%=mod;
 	}
 	return dp[in][sum][flag] = res;
 }
 
 
 
int main() {
	

	cin>>arr;
	cin>>d;
	memset(dp, -1, sizeof dp);
	 
	 long long c= back(1,0,false);
	c-=1; c+=mod;
	 c%=mod;
	 cout<<  c <<'\n'; 
	return 0;
}
