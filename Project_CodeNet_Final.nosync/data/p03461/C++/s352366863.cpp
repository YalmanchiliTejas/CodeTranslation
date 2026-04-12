#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
const int INF=1e9;
void chkmax(int &x,int y){
	x=x>y?x:y;
}
void chkmin(int &x,int y){
	x=x<y?x:y;
}
int d[11][11];
struct edge{
	int s,t,v;
}w[100100];
int num;
void Addedge(int s,int t,int v){
	w[++num]=(edge){s,t,v};
}
int n,m;
int a[101][101];
bool checkans(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int mn=INF;
			for(int p=0;p<=maxn;p++)
				for(int q=0;q<=maxn;q++)
					chkmin(mn,p*i+q*j+a[p][q]);
			if(mn!=d[i][j]) return 0;
		}
	return 1;
}
int main(){
//	freopen("A.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&d[i][j]);
	int S=1,T=maxn*2+2;
	for(int i=1;i<maxn;i++)
		Addedge(i,i+1,-1);
	for(int i=maxn+2;i<T;i++)
		Addedge(i,i+1,-2);
	for(int i=0;i<=maxn;i++)
		for(int j=0;j<=maxn;j++)
			for(int p=1;p<=n;p++)
				for(int q=1;q<=m;q++)
					chkmax(a[i][j],d[p][q]-p*i-q*j);
	for(int i=0;i<=maxn;i++)
		for(int j=0;j<=maxn;j++)
			Addedge(i+1,T-j,a[i][j]);
	if(!checkans())
		printf("Impossible\n");
	else{
		printf("Possible\n");
		printf("%d %d\n",T,num);
		for(int i=1;i<=num;i++){
			printf("%d %d ",w[i].s,w[i].t);
			if(w[i].v==-1) printf("X\n");
			else if(w[i].v==-2) printf("Y\n");
			else printf("%d\n",w[i].v);
		}
		printf("%d %d\n",S,T);
	}
	return 0;
}
