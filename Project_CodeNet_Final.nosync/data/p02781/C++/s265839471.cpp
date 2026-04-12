#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define lson l,mid,p<<1
#define rson mid+1,r,p<<1|1
#define pii pair<int,int>
using namespace std;
const int inf=1e9+10;
const int mod=1e9+7;
const int maxn=1e5+10;
char s[110];
int n,k;
ll dp[110][5];
ll dfs(int pos,int sta,bool limit){
	if(pos==-1) return sta==k;
	if(!limit&&~dp[pos][sta]) return dp[pos][sta];
	int up=limit?s[pos]-'0':9;
	ll ans=0;
	for(int i=0;i<=up;i++){
        if(i&&sta==k) continue;
		ans+=dfs(pos-1,sta+(i!=0),limit&&i==s[pos]-'0');
	}
	if(!limit) dp[pos][sta]=ans;
	return ans;
}
int main(){
	//ios::sync_with_stdio(false);
	//freopen("in","r",stdin);
	memset(dp,-1,sizeof(dp));
	cin>>s>>k;
	n=strlen(s);
	reverse(s,s+n);
	cout<<dfs(n-1,0,true)<<endl;
	return 0;
}
