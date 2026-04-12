#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int N,M,Q,S[400010],T[400010];
ll sum = 0,dist[4001][4001],C[400010];
vector<vector<int>> mst(4010);
int visited[4010] = {0};

int p[4010] = {0},r[4010] = {0};
void init(int N){
	for(int i=0;i<=N;++i) p[i] = i;
}

int root(int a){
	if(p[a] == a) return a;
	return (p[a] = root(p[a]));
}

bool is_same_set(int a,int b){
	return root(a) == root(b);
}

void unite(int a, int b){
	a = root(a);
	b = root(b);
	if(a==b) return;
	if(r[a]<r[b]){
		p[a] = b;
	}else{
		p[b] = a;
		if(r[a] == r[b]) r[a]++;
	}
}

void dfs(int s,int n,ll cost){
	visited[n] = 1;
	for(int i=0;i<mst[n].size();i++){
		int t = mst[n][i];
		if(visited[t]==0){
			ll ma = max(cost,dist[n][t]);
			dist[s][t] = ma;
			dist[t][s] = ma;
			dfs(s,t,ma);
		}
	}
}

int main(){
	cin >> N >> M;
	init(N);
	vector<pair<ll,int>> v;
	for(int i=0;i<M;i++){
		cin >> S[i] >> T[i] >> C[i];
		dist[S[i]][T[i]] = C[i];
		dist[T[i]][S[i]] = C[i];
		v.push_back({C[i],i});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		int t = v[i].second;
		if(!is_same_set(S[t],T[t])){
			sum += C[t];
			unite(S[t],T[t]);
			mst[S[t]].push_back(T[t]);
			mst[T[t]].push_back(S[t]);
		}
	}
	for(int i=1;i<=N;i++){
		dfs(i,i,0);
		for(int j=1;j<=N;j++) visited[j] = 0;
	}
	cin >> Q;
	int a,b;
	for(int i=0;i<Q;i++){
		cin >> a >> b;
		cout << sum-dist[a][b] << endl;
	}
}