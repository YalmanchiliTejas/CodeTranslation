#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1000000000;
struct edge{
	int t,next,v;
}g[210001];
struct data{
	int a,b,v;
}e[210001];
int te,i,j,k,n,m,a[21][21],h[411],tot,dis[411],q[210001],v[411],num,s,t,w,tx,ty,fl;
void addedge(int x,int y,int z){
	//printf("%d %d %d\n",x,y,z);
	g[++tot].t=y;g[tot].next=h[x];h[x]=tot;g[tot].v=z;
	e[++te].a=x;e[te].b=y;e[te].v=z;
}
int gv(int x){
	if (x>=0) return x;
	if (x==-1) return tx;else return ty;
}
int work(int x,int y){
	int i,j,res=0;
	for (i=1;i<=n;i++)
	 for (j=1;j<=m;j++) res=max(res,a[i][j]-i*x-j*y);
	return res;
}
int spfa(){
	int i,j,k,l,r;
	memset(v,0,sizeof(v));
	for (i=1;i<=num;i++) dis[i]=inf;
	l=0;r=1;q[1]=1;dis[1]=0;
	while (l<r){
		j=q[++l];v[j]=0;
		for (i=h[j];i;i=g[i].next)
		 if (dis[g[i].t]>dis[j]+gv(g[i].v)){
		 	dis[g[i].t]=dis[j]+gv(g[i].v);
		 	if (!v[g[i].t]) v[g[i].t]=1,q[++r]=g[i].t;
		 }
	}
	return dis[num];
}
int main(){
	scanf("%d%d",&n,&m);w=105;
	for (i=1;i<=n;i++)
	 for (j=1;j<=m;j++) scanf("%d",&a[i][j]);
	num=2*w;s=1;t=num;tot=te=0;memset(h,0,sizeof(h));
	for (i=1;i<w;i++) addedge(i,i+1,-1),addedge(i+w,i+w+1,-2);
	for (i=0;i<w;i++)
	 for (j=0;j<w;j++) addedge(i+1,2*w-j,work(i,j));
	for (i=fl=1;fl&&i<=n;i++)
	 for (j=1;fl&&j<=m;j++){
	 	tx=i;ty=j;
		k=spfa();
		if (k!=a[i][j]) fl=0;//,printf("** %d %d %d\n",i,j,k);
	 }
	if (!fl){
		puts("Impossible");
	}else{
		puts("Possible");
		printf("%d %d\n",num,te);
		for (i=1;i<=te;i++){
			printf("%d %d ",e[i].a,e[i].b);
			if (e[i].v==-1) printf("X\n");
			if (e[i].v==-2) printf("Y\n");
			if (e[i].v>=0) printf("%d\n",e[i].v);
		}
		printf("%d %d\n",1,num);
	}
	return 0;
}