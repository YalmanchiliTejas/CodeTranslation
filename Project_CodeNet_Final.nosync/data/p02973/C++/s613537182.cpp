#include<bits/stdc++.h>
#define rg register
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int inf=1e9;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	return f*x;
}
struct node {
	int v,son,size,fa,ch[2];
} a[500001];
int root,tot;
void rotate(int x) {
	int y=a[x].fa,z=a[y].fa,k=(a[y].ch[1]==x);
	a[z].ch[a[z].ch[1]==y]=x,a[x].fa=z;
	a[a[x].ch[k^1]].fa=y,a[y].ch[k]=a[x].ch[k^1];
	a[y].fa=x,a[x].ch[k^1]=y;
	a[x].son=a[x].size+a[a[x].ch[0]].son+a[a[x].ch[1]].son;
	a[y].son=a[y].size+a[a[y].ch[0]].son+a[a[y].ch[1]].son;
}
void splay(int x,int top) {
	while(a[x].fa!=top) {
		int y=a[x].fa,z=a[y].fa;
		if(z!=top)
			(a[y].ch[0]==x)^(a[y].ch[0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
	if(!top) root=x;
}
void insert(int x) {
	int u=root,f=0;
	while(u&&a[u].v!=x)
		f=u,u=a[u].ch[x>a[u].v];
	if(u) {
		a[u].size++,splay(u,0);
		return ;
	}
	u=++tot;
	if(f) a[f].ch[x>a[f].v]=u;
	a[u].fa=f,a[u].size=a[u].son=1,a[u].v=x,splay(u,0);
}
void find(int x) {
	int u=root;
	while(a[u].v!=x&&a[u].ch[x>a[u].v]) u=a[u].ch[x>a[u].v];
	splay(u,0);
}
int Next(int x,int f) {
	find(x);
	if((f&&a[root].v>x)||(!f&&x>a[root].v)) return root;
	int u=a[root].ch[f];
	while(a[u].ch[f^1]) u=a[u].ch[f^1];
	return u;
}
void delet(int x) {
	int A=Next(x,0),B=Next(x,1);
	splay(A,0),splay(B,A);
	int u=a[B].ch[0];
	if(a[u].size>1) a[u].size--,splay(u,0);
	else a[B].ch[0]=0;
}
int kth(int x) {
	int u=root;
	if(a[u].son<x) return 0;
	while(1) {
		if(x>a[a[u].ch[0]].son+a[u].size)
			x-=a[a[u].ch[0]].son+a[u].size,u=a[u].ch[1];
		else if(a[a[u].ch[0]].son>=x)
			u=a[u].ch[0];
		else return a[u].v;
	}
}
int main() {
	int n=read(),ans=0;
	insert(inf);
	insert(-inf);
	for(int i=1; i<=n; i++) {
		int x=read();
		int now=a[Next(x,0)].v;
		if(now!=-inf) delet(now),insert(x);
		else insert(x),ans++;
	}
	cout<<ans<<endl;
	return 0;
}
