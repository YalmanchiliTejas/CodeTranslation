#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;

void ERROR(int num) { printf("ERROR%d!\n",num); }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};

int N, M;
vector<vector<int>> G;

void DFS(int v, vector<bool> &seen, int &res){
	bool end = true;
	//全部訪問したかをチェックする
	rep(i,seen.size()){
		if(!seen[i] && i!=v) end = false;
	}
	if(end){//全部訪問したらカウント+1
		res++;
		return;
	}
	seen[v] = true;//現在訪問した所にチャック
	for(auto nv : G[v]){
		if(seen[nv]) continue;
		DFS(nv,seen,res);
	}
	seen[v] = false;
}

int main(){
	cin >> N >> M;
	G.resize(N);
	rep(i,M){
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].pb(b);
		G[b].pb(a);
	}	
	
	vector<bool> seen(N,false);
	int res = 0;
	DFS(0,seen,res);
	cout << res << endl;
}