#include<bits/stdc++.h>
using namespace std;
int c[100][100],k,len=0;
long long dp[101][5];
string n;
int dfs(int idx,bool is0,bool limit,int used){
    if(idx>len)return 0;
	if(idx==len&&used==0)return 1;
	if(!limit&&dp[idx][used]!=-1)return dp[idx][used];
	int maxn=limit?(n[idx]-'0'):9,ans=0;
	for(int i=0;i<=maxn;i++){
		if(i!=0&&used==0)continue;
		if(is0&&i==0)ans+=dfs(idx+1,1,limit&&(i==maxn),used);
		else ans+=dfs(idx+1,0,limit&&(i==maxn),used-(i!=0));
	}
	if(!limit&&!is0)dp[idx][used]=ans;
	return ans;
}
int solve(){
	memset(dp,-1,sizeof(dp));
	return dfs(0,1,1,k);
}
int main(){
    c[0][0]=1;
    for(int i=1;i<100;i++){
        c[i][0]=1;
        for(int j=1;j<100;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    cin>>n>>k;
    len=n.size();
    //cout<<len<<endl;
    cout<<solve()<<endl;
    return 0;
}