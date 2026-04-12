#include<cstdio>
const int N=1e5+5;
int n,i,et,he[N];
struct edge{int l,to;}e[2*N];
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
int dfs(int x,int fa){
	int sum=1;
	for (int i=he[x];i;i=e[i].l)
		if (e[i].to!=fa) sum+=dfs(e[i].to,x);
	if (sum==2) sum=0;return sum;
}
int main(){
	n=read();if (n&1){puts("First");return 0;}
	for (i=1;i<n;i++){
		int x=read(),y=read();
		e[++et].l=he[x];he[x]=et;e[et].to=y;
		e[++et].l=he[y];he[y]=et;e[et].to=x;
	}
	puts(dfs(1,0)?"First":"Second");
}