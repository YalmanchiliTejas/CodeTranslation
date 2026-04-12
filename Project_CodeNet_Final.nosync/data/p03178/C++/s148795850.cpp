#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN=100000+100;
const int MOD=1e9+7;
LL dp[MAXN][128],dgt[MAXN];
LL d,len;
string k;

LL dfs(LL pos,LL num,bool lim){
	if(!lim&&dp[pos][num]!=-1) return dp[pos][num];
	if(pos==len+1) return dp[pos][num]=(num==0);
	LL up=lim?dgt[pos]:9;
	LL ret=0;
	for(int i=0;i<=up;i++){
		ret+=dfs(pos+1,(num+i)%d,lim&&(i==up));
		ret%=MOD;
	}
	if(!lim) dp[pos][num]=ret;
	return ret;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>k>>d;
	len=k.size();
	k='$'+k;
	for(int i=1;i<=len;i++) dgt[i]=k[i]-'0';
	LL ans=dfs(1,0,1)-1+MOD;
	cout<<ans%MOD<<endl;
	return 0;
}
 