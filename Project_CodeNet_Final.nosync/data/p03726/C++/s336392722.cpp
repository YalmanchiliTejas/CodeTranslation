#include<iostream>
using namespace std;
const int N=100005;
struct node { int y,next; } a[N<<1];
int head[N],i,j,k,n,m;
char c;

inline char getc()
{
	#define VV 10000000
	static char s[VV],*l=s,*r=s;
	if (l==r)
		l=s,r=s+fread(s,1,VV,stdin);
	return l==r?0:*l++;
}

int read(){ int z=0; do c=getc(); while (c<'0'||c>'9'); while (c>='0'&&c<='9') z*=10,z+=c-'0',c=getc(); return z; }

void jb(int x,int y)
{
	a[++k]=(node){y,head[x]},head[x]=k,
	a[++k]=(node){x,head[y]},head[y]=k;
}

bool dfs(int w,int sp)
{
	int z=0;
	for (register int j=head[w];j;j=a[j].next)
		if ((j^1)!=sp)
			z+=dfs(a[j].y,j);
	if (z>1)
	{
		puts("First");
		exit(0);
	}
	return z^1;
}

int main()
{
	n=read(),k=1;
	for (i=1;i<n;++i) jb(read(),read());
	puts(dfs(1,0)?"First":"Second");
	return 0;
}