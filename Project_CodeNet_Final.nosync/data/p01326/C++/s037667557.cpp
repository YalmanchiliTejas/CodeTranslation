#include<stdio.h>
#include<string.h>
const long long MOD=1000000;
int X(char*p,char*q)
{
	for(int i=0;q[i];++i)if(p[i]==q[i])return 1;
	return 0;
}
int Y(int r,int x)
{
	while(x--)r*=2,r%=MOD;
	return r;
}
int F(char*p)
{
	if(p[0]=='1')return 0;
	int x=0,i;
	for(i=1;i<8;++i)if(p[i]=='x')++x;
	return 1<<x;
}
int G(char*p,char*q)
{
	if(X(p,"001")||X(q,"01"))return 0;
	int x=0,y=0,f=0,i;
	for(i=3;i<7;++i){if(p[i]=='1')f=1;if(p[i]=='x')++y;}
	x=(p[7]=='x');
	for(i=2;i<8;++i)x+=(q[i]=='x');
	return Y((f?1<<y:(1<<y)-1), x);
}
int H(char*p,char*q,char*r)
{
	if(X(p,"0001")||X(q,"01")||X(r,"01"))return 0;
	int x=0,y=0,f=0,i;
	if(q[2]=='1')f=1;if(q[2]=='x')++y;
	for(i=4;i<8;++i){if(p[i]=='1')f=1;if(p[i]=='x')++y;}
	for(i=3;i<8;++i)if(q[i]=='x')++x;
	for(i=2;i<8;++i)if(r[i]=='x')++x;
	return Y((f?1<<y:(1<<y)-1),x);
}
int I(char*p,char*q,char*r,char*s)
{
	if(X(p,"00001")||X(q,"01")||X(r,"01")||X(s,"01"))return 0;
	int x=0,y=0,f=0,i;
	for(i=5;i<8;++i){if(p[i]=='1')f=1;if(p[i]=='x')++y;}
	for(i=2;i<4;++i){if(q[i]=='1')f=1;if(q[i]=='x')++y;}
	for(i=4;i<8;++i)if(q[i]=='x')++x;
	for(i=2;i<8;++i)if(r[i]=='x')++x;
	for(i=2;i<8;++i)if(s[i]=='x')++x;
	return Y((f?1<<y:(1<<y)-1),x);
}
int n;
long long memo[1000];
char a[1000][16];
long long A(int i)
{
	if(i>=n)return 1;
	if(memo[i]>=0)return memo[i];
	long long r = 0;
	r += F(a[i])*A(i+1);r%=MOD;
	if(i+1<n)r+=G(a[i],a[i+1])*A(i+2),r%=MOD;
	if(i+2<n)r+=H(a[i],a[i+1],a[i+2])*A(i+3),r%=MOD;
	if(i+3<n)r+=I(a[i],a[i+1],a[i+2],a[i+3])*A(i+4),r%=MOD;
	return memo[i]=r;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		memset(memo,-1,sizeof(memo));
		for(int i=0;i<n;++i)scanf("%s",a[i]);
		printf("%d\n",(int)A(0));
	}
	return 0;
}