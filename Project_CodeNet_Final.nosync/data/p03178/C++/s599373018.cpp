#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
const int MAXK=10010;
long long dp[MAXK][110];
int d,a[MAXK];
string k;

inline long long dfs(int pos,int rest,bool limit){
	if(pos==-1) return rest==0;
	if(!limit && dp[pos][rest]!=-1) return dp[pos][rest];
	int up=limit?a[pos]:9;
	long long res=0;
	for(register int i=0;i<=up;++i)
		(res+=dfs(pos-1,(rest+i)%d,limit&&i==a[pos]))%=MOD;
	return dp[pos][rest]=res%MOD;
}

inline long long solve(){
	for(register int i=k.size()-1;i>=0;--i) a[k.size()-1-i]=k[i]-'0';
	return dfs(k.size()-1,0,1);
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>k;
	cin>>d;
	cout<<(solve()-1+MOD)%MOD<<endl;
	return 0;
}