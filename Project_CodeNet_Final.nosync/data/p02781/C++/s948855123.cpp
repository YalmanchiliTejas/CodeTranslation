#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
int n,K,dp[5][105][3];
char str[105];
int dfs(int m,int use,int limit) {
    if(use>K){
    	return 0;
	}
    if(m>n){
    	return use==K;
	}
    if(dp[use][m][limit] != -1){
    	return dp[use][m][limit];
	}
    int up=limit==1?str[m]-'0':9,ans=0;
    for(int i = 0; i <= up; ++i){
    	ans += dfs(m+1, use+(i!=0), limit&&i==up); 
	}
    return dp[use][m][limit]=ans;
}
void run_case() {
    cin>>(str+1)>>K;
    n=strlen(str+1);
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1, 0, 1)<<endl;
}
int main(){
    run_case();
    cout.flush();
    return 0;
}