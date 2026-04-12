#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define DIV 1000000007

using namespace std;

long long N, M, Q;
long long S[100005];
long long T[100005];
long long origin;

vector<pair<long long , long long> >tree[4005];

long long memo[4005][4005];

vector<pair<long long, pair<long long, long long> > >fvec;

// 素集合データ構造
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<int> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
	  // 最初は全てのデータiがグループiに存在するものとして初期化
	  for(int i = 0; i < n; i++){
		  par[i] = i;
	  }
  }

  // データxが属する木の根を得る
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(int x, int y) {
    // データの根ノードを得る
    x = find(x);
    y = find(y);

    // 既に同じ木に属しているならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);

    // xがyの親になるように連結する
    par[y] = x;
    sizes[x] += sizes[y];
    // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // データxが含まれる木の大きさを返す
  int size(int x) {
    return sizes[find(x)];
  }
};


void prepare(){
	UnionFind uf(N + 1);	

	set<long> done;
	long long ans = 0;
	for(int i = 0; i < fvec.size(); i++){
		long long src = fvec[i].second.first;
		long long dst = fvec[i].second.second;
		long long cost = fvec[i].first;
		if(uf.same(src, dst) == false){
			uf.unite(src, dst);
			tree[src].push_back(make_pair(cost, dst));
			tree[dst].push_back(make_pair(cost, src));
			origin += cost;
		}
		if(uf.size(0) == N){
			return;
		}
	}
}

void dfs(long long root, long long pa, long long cur, long long maxi){
	//cout << " root " << root << " pa " << pa << " cur " << cur << endl;
	memo[root][cur] = maxi;
	for(int i = 0; i < tree[cur].size(); i++){
		long long cost = tree[cur][i].first;
		long long next = tree[cur][i].second;
		if(pa != next){
			dfs(root, cur, next, max(maxi, cost));
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		a--;b--;
		fvec.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(fvec.begin(), fvec.end());


	cin >> Q;
	for(int i = 0; i < Q; i++){
		cin >> S[i] >> T[i];
		S[i]--;T[i]--;
	}
	prepare();
	for(int i = 0; i < N; i++){
		dfs(i, -1, i, 0);
	}
	/*
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << i << " -> " << j << ":" << memo[i][j] << endl;
		}
	}
	*/

	for(int i = 0; i < Q; i++){
		cout << origin - memo[S[i]][T[i]] << endl;
	}
}