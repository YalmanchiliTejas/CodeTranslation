#include<cstdio>
#include<algorithm>
int n,m,x[100010],y[100010],list[100010],fa[100010];
bool cmpx(int i,int j){return x[i]<x[j];}
bool cmpy(int i,int j){return y[i]<y[j];}
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);}
struct edge{int u,v,w;bool operator<(const edge&e)const{return w<e.w;}}E[200010];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i),fa[i]=list[i]=i;
	std::sort(list,list+n,cmpx);
	for(int*i=list;i<list+n-1;i++)E[m++]=(edge){*i,i[1],x[i[1]]-x[*i]};
	std::sort(list,list+n,cmpy);
	for(int*i=list;i<list+n-1;i++)E[m++]=(edge){*i,i[1],y[i[1]]-y[*i]};
	std::sort(E,E+m);
	int s=0,b=n;
	for(edge*e=E;b>1;e++)find(e->u)!=find(e->v)?s+=e->w,b--,fa[find(e->u)]=find(e->v):1;
	printf("%d\n",s);
}