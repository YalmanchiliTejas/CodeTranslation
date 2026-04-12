#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include <bits/stdc++.h>



#define  ll long long int
#define REP(i,n) for(int i=0;i<n;i++)
#define v(T,n) vector<T>n
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;

#define D cout<<"Debug"<<endl;

using namespace std;
const ll MOD = 1000000007;
const ll MAX = 65565;
ll fac[MAX], finv[MAX], inv[MAX];
using Graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//--------------------------------------bfs------------------------------------------
	
vector<int> dist;//for bfs
queue<int> que;
	
void bfs(int N, Graph G){
	/* in main, read data
	
	int N,M;
	cin>>N>>M;
	Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
		a-=1;b-=1;
        G[a].push_back(b);
        G[b].push_back(a);
    }
	bfs(N,G);
	
	*/
  // BFS のためのデータ構造
	dist.assign(N,-1);
	
    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
 while (!que.empty()) {  
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}
//--------------------------------------bfs------------------------------------------
//--------------------------------------dfs------------------------------------------
vector<bool> seen;
void dfs(const Graph &G, int v) {
	/*
	int N, M; 
	cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }


    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
	
	*/
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
	
//--------------------------------------dfs------------------------------------------

//--------------------------------------a^n------------------------------------------

ll modpow(ll a, ll  n) { //二分累乗法 a^n
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}
//-------------------------------------a^n------------------------------------------

//--------------------------------------COM nCk------------------------------------------
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k){ //nCk
//use COMinit() before use this.
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
//--------------------------------------COM nCk------------------------------------------


void Main()
{
	int r,g,b;
	cin>>r>>g>>b;
	int a = r*100+g*10+b;
	if(a % 4 == 0){
		YES
	}else{
		NO
	}
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	COMinit();
	Main();
}