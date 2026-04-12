#include <cstdio>
#include <vector>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int V_MAX=100000;
const int M=1000000007;

int main(){
	for(int n,m;~scanf("%d%d",&n,&m);){
		if(n==0) break;

		static vector<int> G[V_MAX];
		rep(u,n) G[u].clear();

		rep(i,m){
			int a,b; scanf("%d%d",&a,&b); a--; b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		// BFS
		int cc=0; // number of connected components of G
		static bool vis[V_MAX];
		rep(u,n) vis[u]=false;
		rep(u,n) if(!vis[u]) {
			cc++;
			vis[u]=true;

			int head=0,tail=0;
			static int Q[V_MAX];
			Q[tail++]=u;
			while(head<tail){
				int v=Q[head++];
				rep(i,G[v].size()){
					int w=G[v][i];
					if(!vis[w]){
						vis[w]=true;
						Q[tail++]=w;
					}
				}
			}
		}

		int ans=1;
		rep(i,cc) ans=2*ans%M;
		if(m>0) ans=(ans+1)%M;
		printf("%d\n",ans);
	}

	return 0;
}