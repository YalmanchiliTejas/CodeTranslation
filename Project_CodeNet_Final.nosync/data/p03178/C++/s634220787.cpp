#include <bits/stdc++.h>
using namespace std;
#define md 1000000007
string s;
int dp[10009][100][2],p,d;
inline int dfs(int n,int z,bool f){
	if(n==s.size()) return !z;
	int &res(dp[n][z][f]);
	if(~res) return res;
	res=0;
	int x=s[n]-'0';
	int r=(f?x:9);
	for(int i=0;i<=r;++i){
    	res+=dfs(n+1,(z+i)%d,f and i==r);
    	if(res>=md) res-=md;
	}
	return res;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>s>>d;
	cout<<(dfs(0,0,1)-1+md)%md<<endl;
}