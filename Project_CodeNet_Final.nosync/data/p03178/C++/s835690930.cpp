#include <bits/stdc++.h> 
using namespace std;
const int mxn = 1e7 , N = 5e5 + 5 , mod = 1e9 + 7;
long long dp[10005][105][2];
bool vis[10005][105][2];
string s;
int siz , n;
long long sol(int idx,int d,int state){
	if(idx==siz){
		if(d==0)
			return 1;
		return 0;
	}
	
	if(vis[idx][d][state]){
		return dp[idx][d][state];
	}
	vis[idx][d][state] = true;
	long long ret = 0;
	if(state){
		for(int i = 0;i<=s[idx]-'0';i++){
			if(i==s[idx]-'0'){
				ret = (ret + sol(idx+1,(d-(i%n)+n)%n,1))%mod;
				continue;
			}
			ret = (ret + sol(idx+1,(d-(i%n)+n)%n,0))%mod;
		}
	}else{
		for(int i = 0;i<=9;i++){
			ret = (ret + sol(idx+1,(d-(i%n)+n)%n,0))%mod;
		}
	}
	
	return dp[idx][d][state] = ret;
}  
int main(){
	cin>>s>>n;
	siz = s.size();
	cout<<(((sol(0 , 0 , 1) - 1) %mod)+ mod) %mod;
	return 0;
}
