#include<cctype>
#include<cstdio>
#include<vector>
#include<cstdlib>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

struct P{ int x,y,cost; };

int main(){
	for(int w,h;scanf("%d%d",&w,&h),w;){
		int B[100][100];
		int sx,sy,gx,gy;
		int lastdgt=0;
		vector<P> dgt[10010];
		rep(i,h) rep(j,w) {
			char ss[16]; scanf("%s",ss);
			if(!isdigit(ss[0])) B[i][j]=0;
			else sscanf(ss,"%d",&B[i][j]);

			if(ss[0]=='S') sx=j, sy=i;
			if(ss[0]=='G') gx=j, gy=i;
			if(isdigit(ss[0])){
				dgt[B[i][j]].push_back((P){j,i,INF});
				lastdgt=max(lastdgt,B[i][j]);
			}
		}
		dgt[    0    ].push_back((P){sx,sy,0});
		dgt[lastdgt+1].push_back((P){gx,gy,INF});

		rep(k,lastdgt+1){
			rep(i,dgt[k].size()) rep(j,dgt[k+1].size()) {
				P p=dgt[k][i],q=dgt[k+1][j];
				dgt[k+1][j].cost=min(q.cost,p.cost+abs(q.x-p.x)+abs(q.y-p.y));
			}
		}
		printf("%d\n",dgt[lastdgt+1][0].cost);
	}

	return 0;
}