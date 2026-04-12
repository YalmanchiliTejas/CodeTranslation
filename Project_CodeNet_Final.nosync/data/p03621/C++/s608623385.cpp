#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

#define DB double
#define LL long long
#define MAXN 10000
#define MOD 998244353
#define Pr pair<int,int>
#define X first
#define Y second
#define INF 1000000001
#define mem(x,v) memset(x,v,sizeof(x))

LL read(){
	LL x=0,F=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*F;
}

int add(int a,int b){return (a+b>=MOD)?a+b-MOD:a+b;}
int dec(int a,int b){return (a-b<0)?a-b+MOD:a-b;}
int mul(int a,int b){return (1LL*a*b)%MOD;}
int fst_pow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=mul(res,a);
		a=mul(a,a),b>>=1;
	}
	return res;
}
void upd(int &a,int b){a=add(a,b);}

int n,s,t,ans;
char a[MAXN+5],b[MAXN+5];
int f[MAXN+5][MAXN+5],fac[MAXN+5],ifac[MAXN+5];

void prepare(){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=fst_pow(fac[n],MOD-2);
	for(int i=n;i>=1;i--)ifac[i-1]=mul(ifac[i],i);
}
int Comb(int a,int b){
	return mul(fac[a],mul(ifac[b],ifac[a-b]));
}

int main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	prepare();
	for(int i=1;i<=n;i++)
	if(a[i]=='1'&&b[i]=='1')s++;
	else if(a[i]>b[i])t++;
	f[0][0]=1;
	for(int i=0;i<=s;i++)
		for(int j=0;j<=t;j++)
		if(f[i][j]){
			upd(f[i+1][j],mul(f[i][j],mul(i+1,j)));
			upd(f[i][j+1],mul(f[i][j],mul(j+1,j+1)));
		}
	for(int i=0;i<=s;i++)
	ans=add(ans,mul(mul(Comb(s,i),Comb(s+t,i)),mul(mul(fac[i],fac[i]),f[s-i][t])));
	printf("%d\n",ans);
}