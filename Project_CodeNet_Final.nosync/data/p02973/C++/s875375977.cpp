#include<bits/stdc++.h>
using namespace std;
struct node{
	int v;
	int son;
	int siz;
	int fa;
	int ch[2];
}a[500007];
int root;
int tot;
void rotat(int x){
	int y=a[x].fa;
	int z=a[y].fa;
	int k=(a[y].ch[1]==x);
	a[z].ch[a[z].ch[1]==y]=x,a[x].fa=z;
	a[a[x].ch[k^1]].fa=y,a[y].ch[k]=a[x].ch[k^1];
	a[y].fa=x,a[x].ch[k^1]=y;
	a[x].son=a[x].siz+a[a[x].ch[0]].son+a[a[x].ch[1]].son;
	a[y].son=a[y].siz+a[a[y].ch[0]].son+a[a[y].ch[1]].son;
}
void splay(int x,int top){
	while(a[x].fa!=top) {
		int y=a[x].fa;
		int z=a[y].fa;
		if(z!=top)
			(a[y].ch[0]==x)^(a[y].ch[0]==y)?rotat(x):rotat(y);
		rotat(x);
	}
	if(!top)
        root=x;
}
void inser(int x){
	int u=root;
	int f=0;
	while(u&&a[u].v!=x)
		f=u,u=a[u].ch[x>a[u].v];
	if(u){
		a[u].siz++;
		splay(u,0);
		return;
	}
	u=++tot;
	if(f)
        a[f].ch[x>a[f].v]=u;
	a[u].fa=f;
	a[u].siz=a[u].son=1;
	a[u].v=x,splay(u,0);
}
void fin(int x){
	int u=root;
	while(a[u].v!=x&&a[u].ch[x>a[u].v])
        u=a[u].ch[x>a[u].v];
	splay(u,0);
}
int nex(int x,int f){
	fin(x);
	if((f&&a[root].v>x)||(!f&&x>a[root].v))
        return root;
	int u=a[root].ch[f];
	while(a[u].ch[f^1])
        u=a[u].ch[f^1];
	return u;
}
void delet(int x){
	int aa=nex(x,0);
	int bb=nex(x,1);
	splay(aa,0),splay(bb,aa);
	int u=a[bb].ch[0];
	if(a[u].siz>1){
        a[u].siz--;
        splay(u,0);
	}
	else
        a[bb].ch[0]=0;
}
int kth(int x){
	int u=root;
	if(a[u].son<x)
        return 0;
	while(1){
		if(x>a[a[u].ch[0]].son+a[u].siz)
			x-=a[a[u].ch[0]].son+a[u].siz,u=a[u].ch[1];
		else if(a[a[u].ch[0]].son>=x)
			u=a[u].ch[0];
		else
            return a[u].v;
	}
}
int main(){
	int n;
	cin>>n;
	int sum=0;
	inser(1e9);
	inser(-1e9);
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		int now=a[nex(x,0)].v;
		if(now!=-1e9){
            delet(now);
            inser(x);
		}
		else{
            inser(x);
            sum++;
		}
	}
	cout<<sum;
	return 0;
}
