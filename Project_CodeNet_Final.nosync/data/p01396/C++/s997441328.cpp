//esAeñ²ÆÉª¯Äl¦é
//Åå³ª¶Ý·éA©ÂÅ¬pXí¢ª2Èº©Ç¤©ð»è·êÎÇ¢

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_W = 1009;
const int INF = 1<<29;
int H, W;

const int MAX_V = 2003;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];
 
void add_edge(int u, int v){G[v].push_back(u);G[u].push_back(v);}
bool dfs(int v){used[v] = true;for(int i=0; i<G[v].size(); i++){int u = G[v][i], w = match[u];if(w<0 || !used[w] && dfs(w)){match[v] = u;match[u] = v;return true;}}return false;}
int bipartite_matching(){int ret = 0;memset(match, -1, sizeof(match));for(int v=0; v<V; v++)if(match[v] < 0){memset(used, 0, sizeof(used));if(dfs(v)) ret++;}return ret;}

bool graph[MAX_W][MAX_W];

int nums[MAX_W][MAX_W];
int tmp[MAX_W][MAX_W];
vector<int> X[MAX_W];

//A > B©Ç¤©
bool cmp_v(const vector<int>& a, const vector<int>& b){

	for(int i=0; i<W; i++){
		if(a[i] < b[i]) return false;
	}

	return true;
}

bool solve(){
	for(int i=0; i<H; i++){
		X[i].clear();
	}

	int maxi = -1, key = -1;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(maxi < nums[i][j]){
				maxi = nums[i][j];
				key = i;
			}
		}
	}

	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			X[i].push_back(nums[i][j]);
		}
	}

	vector<int> best_vec = X[key];

	sort(X, X+H);
	reverse(X, X+H);

	for(int j=1; j<H; j++){
		if( !cmp_v(X[0], X[j]) ){
			return false;
		}
	}

	//DAGðÂ­é
	V = 2*H;
	for(int i=0; i<V; i++){
		G[i].clear();
	}
	
	memset(graph, 0, sizeof(graph));
	for(int i=H-1; i>=0; i--){
		for(int j=i+1; j<H; j++)if( !graph[i][j] ){
			if( cmp_v(X[i], X[j]) ){
				graph[i][j] = true;
				add_edge(i, j+H);
				for(int k=0; k<H; k++){
					graph[i][k] |= graph[j][k];
				}
			}
		}
	}

	if(best_vec != X[0]){
		return false;
	}

	return (H - bipartite_matching()) <= 2;
}

bool sub_solve(){

	if(!solve()){
		return false;
	}

	//swap
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			tmp[j][i] = nums[i][j];
		}
	}

	swap(H, W);
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			nums[i][j] = tmp[i][j];
		}
	}

	return solve();

}

int main(){

	scanf("%d%d",&H, &W);
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			scanf("%d", nums[i]+j);
		}
	}

	bool ans = sub_solve();

	puts(ans?"YES":"NO");

	return 0;
}