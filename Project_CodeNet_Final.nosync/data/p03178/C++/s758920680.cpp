#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long solve(string& k,int D,vector<vector<vector<long>>>& dp,int pos,int d,bool tight){
    if(dp[pos][d][tight]!=-1){
        return dp[pos][d][tight];
    }
     int ub;
    if(tight==1){
        ub=(k[pos]-'0');
    }
    else{
        ub = 9;
    }
    if(pos==(k.length())){
       if(d==0){
           return 1;
       }
       else{
           return 0;
       }
    }
    long long int ans =0 ;
    for(int i=0;i<=ub;i++){
     ans = (ans%mod + solve(k,D,dp,pos+1,(D + d -i%D)%D,(tight&&(i==ub)))%mod)%mod;
    }
    return dp[pos][d][tight] = ans;
    }
int main() {
	string k;
	cin>>k;
	int D;
	cin>>D;
	vector<vector<vector<long>>> dp(100001,vector<vector<long>>(101,vector<long>(2,-1)));
	cout<<(mod+solve(k,D,dp,0,0,1)-1)%mod<<'\n';
	return 0;
}