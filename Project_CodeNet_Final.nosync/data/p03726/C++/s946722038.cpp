#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f

using namespace std;

struct Edge {
  int t,next;
  Edge() {}
  Edge(int a,int b):t(a),next(b) {}
};

Edge e[200005];
int head[100005];

int f[100005][2];

void dfs(int x,int fa) {
  f[x][1]=-inf;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) {
    	int u=e[i].t;
    	dfs(u,x);
    	f[x][0]+=max(f[u][0],f[u][1]);
    	f[x][1]=max(f[x][1],f[u][0]+2-max(f[u][0],f[u][1]));
	}
  f[x][1]+=f[x][0];
}

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<n;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	e[2*i-1]=Edge(y,head[x]);
  	head[x]=2*i-1;
  	e[2*i]=Edge(x,head[y]);
  	head[y]=2*i;
  }
  dfs(1,0);
  puts((max(f[1][0],f[1][1])==n)?"Second":"First");
  return 0;
}