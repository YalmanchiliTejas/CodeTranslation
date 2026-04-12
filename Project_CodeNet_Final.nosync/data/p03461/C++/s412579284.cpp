#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A,B,cnt,d[11][11];
bool b[11][11];
struct edge{
	int s,t,w;
	edge():s(0),t(0),w(0){}
	edge(int s,int t,int w):s(s),t(t),w(w){}
}es[40005];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';f=c=='-'?-1:1,c=getchar());
	for(;c>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0',c=getchar());
	return x*f;
}
int main(){
	A=read();B=read();
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
			d[i][j]=read();
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++){
			int maxw=0;
			for(int k=1;k<=A;k++)
				for(int l=1;l<=B;l++)
					maxw=max(maxw,d[k][l]-k*i-l*j);
			es[++cnt]=edge(i+1,202-j,maxw);
			for(int k=1;k<=A;k++)
				for(int l=1;l<=B;l++)
					if(d[k][l]==k*i+l*j+maxw)b[k][l]=1;
		}
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
			if(!b[i][j])return 0*puts("Impossible");
	printf("Possible\n202 %d\n",cnt+200);
	for(int i=1;i<=100;i++)printf("%d %d X\n%d %d Y\n",i,i+1,i+101,i+102);
	for(int i=1;i<=cnt;i++)printf("%d %d %d\n",es[i].s,es[i].t,es[i].w);
	puts("1 202");
	return 0;
}