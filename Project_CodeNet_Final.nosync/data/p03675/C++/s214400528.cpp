#include<stdio.h>
#include<algorithm>
#define N 200005
using namespace std;
int rev[N],son[N][2],Q[N],F[N],a[N];
int n,i,x;
void down(int x){
	if (!rev[x]) return;rev[x]=0;
	rev[son[x][0]]^=1;rev[son[x][1]]^=1;
	swap(son[x][0],son[x][1]);
}
void Rotate(int x){
	int y=F[x],z=F[y],w=son[y][0]==x;
	if (son[y][w^1]=son[x][w]) F[son[x][w]]=y;
	if (z) son[z][son[z][1]==y]=x;
	son[x][w]=y;F[y]=x;F[x]=z;//up(y);up(x);
}
void Splay(int x){
	*Q=0;for (int y=x;y;y=F[y]) Q[++*Q]=y;
	for (int i=*Q;i;i--) down(Q[i]);
	while (F[x]){
		int y=F[x],z=F[y];
		if (z) Rotate(((son[z][1]==y)^(son[y][1]==x))?y:x);
		Rotate(x);
	}//up(x);
}

void DFS(int x){
	if (son[x][0]) DFS(son[x][0]);
	printf("%d ",a[x]);
	if (son[x][1]) DFS(son[x][1]);
}
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=2;i<=n;i++){
		for (x=i-1;;){
			down(x);
			if (son[x][1]) x=son[x][1];else break;
		}
		F[son[x][1]=i]=x;Splay(i);
		rev[i]^=1;
	}
	Splay(1);DFS(1);
}