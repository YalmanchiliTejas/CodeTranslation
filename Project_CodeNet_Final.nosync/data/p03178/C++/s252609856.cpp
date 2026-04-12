#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
string k;
int d,len;
int a[100005];
ll dp[100005][105];
ll DFS(int pos,int v,bool lim){
	if(pos==len+1){
		return dp[pos][v]=(v==0);
	}
	if(!lim&&dp[pos][v]!=-1){
		return dp[pos][v];
	}
	int Lim=lim?a[pos]:9;
	ll res=0;
	for(int i=0;i<=Lim;++i){
		res+=DFS(pos+1,(v+i)%d,lim&&(i==Lim));
		if(res>=mod){
			res-=mod;
		}
	}
	if(!lim){
		dp[pos][v]=res;
	}
	return res;
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>k>>d;
	len=k.size();
	k=' '+k;
	for(int i=1;i<=len;++i){
		a[i]=k[i]-'0';
	}
	cout<<(DFS(1,0,1)-1+mod)%mod<<'\n';
	return 0;
}