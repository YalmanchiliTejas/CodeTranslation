#include <bits/stdc++.h>
using namespace std;
int n,x,y,k;
long long ans=0;
const int inf = 0x3f3f3f3f;
#define ft first
#define se second
const int maxn=100007;
pair <int,int> r[maxn];
pair <int,int> c[maxn];
struct Node{
	int u,v,cst;
}ege[2*maxn+1000];
Node make_node(int a,int b,int c){
	Node node;
	node.u=a;
	node.v=b;
	node.cst=c;
	return node;
}
int f[maxn],rnk[maxn];
int fnd(int x){
	if (f[x]==x)return x;
	return f[x]=fnd(f[x]);
}
void merge(int x,int y){
	x=fnd(x);
	y=fnd(y);
	if (rnk[x]>rnk[y])f[y]=x;
	else {
		f[x]=y;
		if (rnk[x]==rnk[y])rnk[y]++;
	}
}
bool cmp(Node a,Node b){
	return a.cst<b.cst;
}
void K(){
	for (int i=1;i<=k;++i){
		if (fnd(ege[i].u)==fnd(ege[i].v))continue;
		ans+=ege[i].cst;
		merge(ege[i].u,ege[i].v);
//		printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d%d",&x,&y);
		r[i]=make_pair(x,i);
		c[i]=make_pair(y,i);
	}
	sort(r,r+n);
	sort(c,c+n);
	for (int i=1;i<n;++i){
		ege[++k]=make_node(r[i-1].se,r[i].se,abs(r[i].ft-r[i-1].ft));
		ege[++k]=make_node(c[i-1].se,c[i].se,abs(c[i].ft-c[i-1].ft));
	}
	sort(ege+1,ege+1+k,cmp);
	memset(f,inf,sizeof f);
	for (int i=0;i<n;++i)f[i]=i,rnk[i]=1;
	K();
	return 0;
}