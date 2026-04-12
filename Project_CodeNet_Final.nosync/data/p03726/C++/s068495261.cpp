#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int deg[MAXN], vis[MAXN];
vector<int> E[MAXN];
int fa[MAXN];
int h[MAXN];

int getfather(int x){
	if (fa[x] == x) return x;
	else return fa[x] = getfather(fa[x]);
}

int umi;

void nico(){
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= n; i++)
		if (deg[i] == 2){
			int p = getfather(E[i][0]);
			int q = getfather(E[i][1]);
			fa[q] = p;
		}
	for(int i = 1; i <= n; i++)
		getfather(i);
	int cnt = 0;
	map<int, int> mp;
	for(int i = 1; i <= n; i++){
		mp[getfather(i)] = 0;
	}
	for(int i = 1; i <= n; i++){
		if (deg[i] == 1){
			int p = E[i][0];
			auto maki = mp.find(fa[p]);
			maki->second++;
			if (maki->second == 2){
				puts("First");
				umi = 1;
				return ;
			}
		}
	}
	umi = 0;
	puts("Second");
}

int eli = 0;

void dfs(int u, int fa){
	h[u] = -1;
	if (deg[u] == 1 && fa){
		h[u] = -1;
		return ;
	}
	for(int v, i = 0; i < E[u].size(); i++)
		if ((v = E[u][i]) != fa){
			dfs(v, u);
		}
	int p = 0, q = 0, r = 0;
	for(int v, i = 0; i < E[u].size(); i++)
		if ((v = E[u][i]) != fa){
			p += h[v] == 1;
			q += h[v] == -1;
			r += h[v] == 0;
		}
//	cout << u << ' '<<p <<' ' <<q << ' '<< r << endl;
	if (q >= 2){
		eli = 1;
		return ;
	}
	if (q >= 1)
		h[u] = 1;
	
	/*
	if (r == 0 && q == 0){
		h[u] = -1;
		return ;
	}
	if (r == 0 && p == 0){
		h[u] = 1;
		return ;
	}*/
}

void maki(){
	dfs(1, 0);
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
		deg[x]++, deg[y]++;
	}
	maki();
	if (eli || h[1] == -1){
		puts("First");
	}
	else
		puts("Second");
	//nico();
	return ;
	for(int i = 1; i <= n; i++)
		vis[i] = 0;
	for(int i = 1; i <= n; i++)
		if (deg[i] == 1){
			int y, x = i, cnt = 1;
			for(y = E[x][0]; deg[y] == 2; cnt++){
				if (cnt & 1){
					vis[y]++;
				}
				int z = E[y][0] + E[y][1] - x;
				x = y;
				y = z;
			}
			if (cnt & 1){
				vis[y]++;
			}
		}
	int flag = 0;
	for(int i = 1; i <= n; i++)
		if (vis[i] >= 2)
			flag = 1;
	assert(flag == umi);
	//cout << (flag ? "First" : "Second") << endl;
}

void printans(){

}

int main(){
	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}