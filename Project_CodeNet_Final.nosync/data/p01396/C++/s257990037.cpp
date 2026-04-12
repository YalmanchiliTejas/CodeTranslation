#include<cstdio>
#include<vector>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int V_MAX=1000;

bool augment(int u,bool *vis,int match[2][V_MAX],const vector<int> *G){
	if(u==-1) return true;

	rep(i,G[u].size()){
		int v=G[u][i];
		if(!vis[v]){
			vis[v]=true;
			if(augment(match[1][v],vis,match,G)){
				match[0][u]=v;
				match[1][v]=u;
				return true;
			}
		}
	}
	return false;
}

int bipartite_matching(int L,int R,const vector<int> *G){
	static int match[2][V_MAX];
	rep(u,L) match[0][u]=-1;
	rep(v,R) match[1][v]=-1;

	int res=0;
	static bool vis[V_MAX];
	rep(u,L){
		rep(v,R) vis[v]=false;
		if(augment(u,vis,match,G)) res++;
	}
	return res;
}

bool solve(int h,int w,const int a[1000][1000]){
	vector<int> G[1000];
	rep(i1,h) rep(i2,h) {
		bool ok=true;
		rep(j,w) if(a[i1][j]<=a[i2][j]) { ok=false; break; }
		if(ok) G[i1].push_back(i2);
	}

	bool top=false; // 山頂が存在するかどうか
	rep(i,h) if(G[i].size()==h-1) top=true;

	return top && h-bipartite_matching(h,h,G)<=2;
}

int main(){
	int h,w; scanf("%d%d",&h,&w);
	static int a1[1000][1000],a2[1000][1000];
	rep(i,h) rep(j,w) scanf("%d",a1[i]+j), a2[j][i]=a1[i][j];

	puts(solve(h,w,a1)&&solve(w,h,a2)?"YES":"NO");

	return 0;
}