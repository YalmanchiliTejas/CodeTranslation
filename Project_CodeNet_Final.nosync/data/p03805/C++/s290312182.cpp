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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};

int N, M;
vector<vector<int>> G;

void PRINT(vector<bool> &seen){
	for(auto vis: seen){
		cout << vis << " ";
	}
	cout << endl;
}

void DFS(int v, vector<bool> &seen, int &res){
	//seen[v] = 1;

	bool ok = 1;
	rep(i,seen.size()){
		if(i==v) continue;
		if(seen[i]==0) ok=0;
	}
	if(ok){
		res++;
		return;
	}

	 seen[v] = 1;
	for(auto nv : G[v]){
		if(seen[nv]) continue;
		DFS(nv,seen,res);
	}

	seen[v] = 0;
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

	vector<bool> seen(N, false);
	int res = 0;
	DFS(0,seen,res);
	cout << res << endl;
}