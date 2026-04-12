#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=1e4+7,M=107;
const ll mod=1e9+7;

int K[N],D;
ll dp[N][M],vis[N][M];
int n;

ll dfs(int pos,int sum,int lim){
	if(!lim&&vis[pos][sum]) return dp[pos][sum];
	if(pos==n+1){if(!sum) return 1;return 0;}
	int mx=lim? K[pos]:9;ll res=0;
	for(int i=0;i<=mx;i++){
		res=(res+dfs(pos+1,(sum+i)%D,lim&&(i==mx)))%mod;
	}
	if(!lim) dp[pos][sum]=res,vis[pos][sum]=1;
	return res;
}

int main(){
	char ch=getchar();
	while(ch>='0'&&ch<='9') K[++n]=ch-'0',ch=getchar();
	D=input();
	printf("%lld\n",(dfs(1,0,1)-1+mod)%mod);
}