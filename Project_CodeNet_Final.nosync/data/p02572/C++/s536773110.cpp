#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include<bitset>
#include<cstdlib>
#include<set>
#include<unordered_map>
#define l(x) (x<<1)
#define r(x) ((x<<1)|1)
#define low(x) (x&(-x))
#define IL inline
#define reg register
#define LL long long
#define N 500010
#define MO 1000000007
#define INF 0x3f3f3f3f
using namespace std;

LL T,n,m,i,j,k,x,y,z,Ans,sum,cnt;
LL a[N],b[N];
char c[N];

struct Data{
	LL x,y;
}d[N];

IL LL Abs(LL x){return (x<0)?-x:x;}
IL void Swap(LL &a,LL &b){a^=b^=a^=b;}
IL LL Min(LL a,LL b){return (a<b)?a:b;}
IL LL Max(LL a,LL b){return (a>b)?a:b;}
IL bool cmp(const Data a,const Data b){return a.x<b.x;}

IL LL Mi(LL x,LL y){
	LL p=x,t=1,Res=1;
	for (;t<=y;(t&y)?Res=(Res*p)%MO:0,p=(p*p)%MO,t<<=1);
	return Res;
}

IL LL read(){
	LL p=0,f=1;	char	c=getchar();
	while (c<48||c>57)	{if (c=='-')	f=-1;	c=getchar();}
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p*f;
}

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	n=read();
	for (i=1;i<=n;i++)	a[i]=read();
	for (i=1;i<=n;i++)	b[i]=(b[i-1]+a[i])%MO;
	for (i=1;i<n;i++){
		x=(b[n]-b[i]+MO)%MO;
		Ans=(Ans+(x*a[i])%MO)%MO;
	}
	cout<<Ans<<endl;
	return 0;
}