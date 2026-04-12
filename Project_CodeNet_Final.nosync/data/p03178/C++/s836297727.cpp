#include <bits/stdc++.h>
#define ll long long
#define re register
#define IL inline
using namespace std;
const int maxn=1e4+5;
const int maxd=100+5;
const int mod=1e9+7;
template<typename T> void fread(T &x){
	T f=1;x=0;
	char s=getchar();
	while(s<'0' || s>'9'){if(s=='-') f=-1;s=getchar();}
	while(s>='0' && s<='9'){x=(x<<3)+(x<<1)+s-48;s=getchar();}
	x*=f;
}
string s;
int d,pos[maxn];
ll dp[maxn][maxd];
ll dfs(int st,int sta,bool lim){
	if(st==s.size()) return dp[st][sta]=(sta==0);
	if(!lim && dp[st][sta]!=-1) return dp[st][sta];
	int up=lim?pos[st]:9;
	ll ret=0;
	for(re int i=0;i<=up;i++){
		(ret+=dfs(st+1,(sta+i)%d,lim&&(i==pos[st])))%=mod;
	}
	if(!lim) dp[st][sta]=ret;
	return ret;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(dp,-1,sizeof dp);
	cin>>s>>d;
	for(re int i=0;i<s.size();i++) pos[i]=s[i]-'0';
	cout<<(dfs(0,0,1)-1+mod)%mod<<endl;
	return 0;
}
