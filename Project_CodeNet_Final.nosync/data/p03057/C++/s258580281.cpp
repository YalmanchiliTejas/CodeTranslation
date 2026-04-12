#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo=1000000007;
const int N=200005;
int n,m;
char s[N];
int f[N][2][2];
void solve1(){
	f[1][0][0]=f[1][1][1]=1;
	For(i,2,n) For(j,0,1) For(k,0,1) For(l,0,1)
		if (k|l) f[i][j][l]=(f[i][j][l]+f[i-1][j][k])%mo;
	int ans=0;
	For(i,0,1) For(j,0,1)
		if (i|j) ans=(ans+f[n][i][j])%mo;
	printf("%d\n",ans);
}
int pre[N];
int g[N],h[N];

void solve2(){
	pre[1]=1;
	int mnv=(1<<30);
	For(i,2,m)
		pre[i]=(s[i]==s[i-1]?pre[i-1]:0)+1;
	For(i,2,m) if (s[i-1]=='R'&&s[i]!='R')
		if (pre[i-1]==i-1){
			if (pre[i-1]%2==0) mnv=min(mnv,pre[i-1]+1);
			else mnv=min(mnv,pre[i-1]);
		}
		else if (pre[i-1]%2==1)
			mnv=min(mnv,pre[i-1]);
	g[0]=h[0]=1;
	For(i,1,n){
		g[i]=((i>=2?h[i-2]:0)+mo-(i>=mnv+3?h[i-mnv-3]:0))%mo;
		h[i]=(g[i]+(i>=2?h[i-2]:0))%mo;
	}
	int ans=0;
	for (int i=2;i<=min(mnv+1,n);i+=2)
		ans=(ans+1ll*i*g[n-i])%mo;
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	if (s[1]=='B'){
		For(i,1,m)
			if (s[i]=='R') s[i]='B';
			else s[i]='R';
	}
	bool flag=0;
	For(i,1,m) if (s[i]!=s[1]) flag=1;
	if (!flag) return solve1(),0;
	solve2();
}
/*
偶数个R||B回到该端点 
奇数个R||B到达另一端点

RBRBRBRBRB

一段长度为奇数的开头字母 
*/