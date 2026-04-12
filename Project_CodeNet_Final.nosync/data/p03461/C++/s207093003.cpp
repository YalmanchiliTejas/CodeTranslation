#include <bits/stdc++.h>
using namespace std;

int n,m,s,t;
int a,b,d[15][15];

inline void init(){
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
			scanf("%d",d[i]+j);
}

int fl,ga[300][300];
struct edge{
	int u,v,w;
}ge[100005];

inline int check(int x,int y,int c){
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
			if(i*x+j*y+c<d[i][j])return 0;
	return 1;
}

inline void solve(){
	s=1;t=n=202;
	for(int i=1;i<=100;++i)
		ge[m++]=(edge){i,i+1,-1};
	for(int i=102;i<n;++i)
		ge[m++]=(edge){i,i+1,101};
	
	for(int i=1;i<=a;++i){
		for(int j=1;j<=b;++j){
			int ok=0;
			for(int x=0;x<=d[i][j]/i;++x){
				for(int y=0;y<=(d[i][j]-x*i)/j;++y){
					int c=d[i][j]-x*i-y*j;
					if(check(x,y,c)){
						if(!ga[x][y]){
							ga[x][y]=1;
							ge[m++]=(edge){x+1,n-y,c};
						}
						ok=1;break;
					}
				}
				if(ok)break;
			}
			if(!ok){fl=1;break;}
		}
		if(fl)break;
	}
	
	if(fl){puts("Impossible");return;}
	printf("Possible\n%d %d\n",n,m);
	for(int i=0;i<m;++i){
		printf("%d %d ",ge[i].u,ge[i].v);
		if(ge[i].w<0)puts("X");
		else if(ge[i].w>100)puts("Y");
		else printf("%d\n",ge[i].w);
	}
	printf("%d %d\n",s,t);
}

int main(){
	init();
	solve();
	return 0;
}