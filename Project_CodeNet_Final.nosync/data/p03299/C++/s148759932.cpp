/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-03-09 16:15:41
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define i64 long long
const int N=100010,L=20,mod=1000000007,i2=(mod+1)/2;
i64 power(i64 a,i64 b,i64 p)
{
	i64 r=1;
	for(;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p;
	return r;
}
int n,h[N],m[N][L+2],b[N];
int Min(int a,int b){ return h[a]<h[b]?a:b; }
int cmin(int l,int r)
{
	int B=b[r-l+1];
	return Min(m[l][B],m[r-(1<<B)+1][B]);
}
#define info std::pair<i64,i64>
info operator+(info a,i64 b){ a.first-=a.second; a.second=a.second*power(2,b,mod)%mod; return info((a.first+a.second+mod)%mod,a.second); }
info operator+(info a,info b){ return info(a.first*b.first%mod,a.second*b.second%mod*i2%mod); }
info calc(int l,int r,int H)
{
	if(l>r) return info(1,2);
	if(l==r) return info(2,2)+(h[l]-H-1);
	int m=cmin(l,r);
	return (calc(l,m-1,h[m]-1)+info(2,2)+calc(m+1,r,h[m]-1))+(h[m]-H-1);
}
int main()
{
	n=read();
	fr(i,1,n) h[i]=read();
	fr(i,2,n) b[i]=b[i>>1]+1;
	fr(i,1,n) m[i][0]=i;
	fr(j,1,L) fr(i,1,n-(1<<j)+1) m[i][j]=Min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
	printf("%d\n",int(calc(1,n,0).first));
	return 0;
}