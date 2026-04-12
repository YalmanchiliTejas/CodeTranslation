#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<queue>
#include<set>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n,be[120000],x[120000],y[120000],d[120000],et,tot,con[120000];
struct edg{
	int y,ne;
};
edg e[220000];
inline void add_edge(int x,int y){
	e[++et].y=y;
	e[et].ne=be[x];
	be[x]=et;
}
int q[120000],he,ta;
int main(){
	scanf("%d",&n);
	fo(i,2,n){
		scanf("%d%d",&x[i],&y[i]);
		add_edge(x[i],y[i]);
		add_edge(y[i],x[i]);
		d[x[i]]++;
		d[y[i]]++;
	}
	fo(i,1,n)
		if (d[i]==1) q[++ta]=i;
	he=1;
	while (he<=ta){
		int &x=q[he];
		int i=be[x],y;
		while (i){
			if (d[e[i].y]){
				y=e[i].y;
				break;
			}
			i=e[i].ne;
		}
		if (d[y]==2){
			//printf("cut%d %d\n",x,y);
			d[y]-=2;
			i=be[y];
			while (i){
				if (d[e[i].y]){//!!!!!!!
					d[e[i].y]--;
					if (d[e[i].y]==1) q[++ta]=e[i].y;
					if (d[e[i].y]==2&&con[e[i].y]) q[++ta]=con[e[i].y];		
				}
				i=e[i].ne;
			}
		}
		else{
			if (con[y]&&con[y]!=x){//!!!!!! forgot con[y]!=x
				printf("First\n");
				return 0;
			}
			con[y]=x;
		}
		he++;
	}
	bool du=0;
	fo(i,1,n) if (d[i]){
		du=1;
		break;
	}
	if (!du){
		printf("First\n");
		return 0;
	}
	fo(x,1,n){
		tot=0;
		int i=be[x];
		while (i){
			if (d[e[i].y]==1) tot++;
			i=e[i].ne;
		}
		if (tot>=2){
			printf("First\n");
			return 0;
		}
	}
	printf("Second\n");
	return 0;
}