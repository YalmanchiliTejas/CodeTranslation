#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 100
using namespace std;
inline int in(){
    int x=0;bool f=0; char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
struct edge{
	int fr,to,val;
}e[(MN*MN<<1)+5];
int d[13][13],a,b,cnt;
bool vis[13][13];
int main()
{
	a=in();b=in();
	for (int i=1;i<=a;++i)
	for (int j=1;j<=b;++j) d[i][j]=in();
	for (int i=0;i<=MN;++i)
	for (int j=0;j<=MN;++j){
		int mx=0;
		for (int k=1;k<=a;++k)
		for (int l=1;l<=b;++l) mx=max(mx,d[k][l]-i*k-j*l);
		e[++cnt].fr=i+1;e[cnt].to=((MN+1)<<1)-j;e[cnt].val=mx;
		for (int k=1;k<=a;++k)
		for (int l=1;l<=b;++l)
		if (d[k][l]==mx+i*k+j*l) vis[k][l]=1;
	}
	for (int i=1;i<=a;++i)
	for (int j=1;j<=b;++j)
	if (!vis[i][j]) {puts("Impossible");return 0;}
	puts("Possible");printf("202 %d\n",cnt+(MN<<1));
	for (int i=1;i<=MN;++i) printf("%d %d X\n%d %d Y\n",i,i+1,i+MN+1,i+MN+2);
	for (int i=1;i<=cnt;++i) printf("%d %d %d\n",e[i].fr,e[i].to,e[i].val); 
	puts("1 202");return 0;
}