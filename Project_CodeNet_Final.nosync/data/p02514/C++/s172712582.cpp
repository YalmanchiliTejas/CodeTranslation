#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <set>
using namespace std;

typedef long long int64;

const int64 MAX_V = 109;
const int64 INF = 1LL<<50;
struct edge{ int64 to, cap, rev; };
vector<edge> G[MAX_V];
vector<edge> GG[MAX_V];
int64 level[MAX_V];
int64 iter[MAX_V];
int N, M;
bool graph[MAX_V][MAX_V];

vector<bool> g[MAX_V];
int64 cost[MAX_V][MAX_V];

const int MAX_UF = 109;
int pars[MAX_UF];
void init(int n){for(int i=0;i<n;i++)pars[i]=i;}
int getRoot(int x){return x==pars[x]?x:(pars[x]=getRoot(pars[x]));}
bool isSame(int x, int y){return getRoot(x)==getRoot(y);}
void merge(int x, int y){pars[getRoot(x)]=getRoot(y);}

int main(){
	while(scanf("%d%d",&N,&M),N){
		for(int i=0; i<N; i++) g[i] = vector<bool>(N,false);
		for(int i=0; i<N; i++)for(int j=0; j<N; j++) cost[i][j] = 0;
		int64 minus = 0;
		init(N);
		for(int i=0; i<M; i++){
			int x, y;
			int64 z;
			scanf("%d%d%lld",&x,&y,&z);
			if(z<=0){
				minus += z;
				continue;
			}
			g[x][y] = true;
			cost[x][y] = z;
			merge(x,y);
		}
		set<int> ps;
		for(int i=0; i<N; i++) ps.insert(getRoot(i));
		if(ps.size()>1){
			printf("%d\n",(int)minus);
			continue;
		}
		for(int k=0; k<N; k++)for(int i=0; i<N; i++)for(int j=0; j<N; j++){
			g[i][j] = (g[i][j] || (g[i][k] && g[k][j]));
		}
		map<vector<bool>, vector<int> > dict;
		for(int i=0; i<N; i++){
			dict[g[i]].push_back(i);
		}
		int64 ans = 1LL<<60;
		vector<int> tp;
		for(int i=0; i<N; i++)if(dict[g[i]].size()>1)tp.push_back(i);
		vector<int64> cs;
		for(int i=0; i<tp.size(); i++)for(int j=0; j<tp.size(); j++)if(cost[tp[i]][tp[j]]){
			cs.push_back(cost[tp[i]][tp[j]]);
		}
		if(cs.size()>=2){
			sort(cs.begin(), cs.end());
			ans = min(ans, cs[0]+cs[1]);
		}

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)if(i!=j && dict[g[i]]!=dict[g[j]] && cost[i][j]){
				ans = min(ans, cost[i][j]);
			}
		}
		if(ans + minus >= (1LL<<31)){
			printf("%d\n",(int)minus);
		}
		else{
			printf("%d\n",(int)(ans+minus));
		}
	}
	return 0;
}