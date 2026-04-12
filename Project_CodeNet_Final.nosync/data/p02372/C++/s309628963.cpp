#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct rerooting{
	vector<T> dp1;
	vector<T> dp2;
	T E;
	function<T(T, T)> add;
	function<T(T, T)> root;
	void dfs1(vector<vector<pair<int, int>>> &c, int v){
		dp1[v] = E;
		for (auto P : c[v]){
			int w = P.second;
			dfs1(c, w);
			dp1[v] = add(dp1[v], root(dp1[w], P.first));
		}
	}
	void dfs2(vector<vector<pair<int, int>>> &c, int v){
		int deg = c[v].size();
		vector<T> L(deg + 1, E);
		for (int i = 0; i < deg; i++){
			L[i + 1] = add(L[i], root(dp1[c[v][i].second], c[v][i].first));
		}
		vector<T> R(deg + 1, E);
		for (int i = deg - 1; i >= 0; i--){
			R[i] = add(R[i + 1], root(dp1[c[v][i].second], c[v][i].first));
		}
		for (int i = 0; i < deg; i++){
			dp2[c[v][i].second] = root(add(dp2[v], add(L[i], R[i + 1])), c[v][i].first);
			dfs2(c, c[v][i].second);
		}
	}
	rerooting(vector<vector<pair<int, int>>> &c, function<T(T, T)> add, function<T(T, T)> root, T E): add(add), root(root), E(E){
		int N = c.size();
		dp1 = vector<T>(N);
		dfs1(c, 0);
		dp2 = vector<T>(N);
		dfs2(c, 0);
	}
	T operator [](int k){
		return root(add(dp1[k], dp2[k]), 0);
	}
};
int add(int a, int b){
  return max(a, b);
}
int root(int a, int b){
  return a + b;
}
vector<vector<pair<int, int>>> child(vector<vector<pair<int, int>>> E, int r){
	int N = E.size();
	vector<vector<pair<int, int>>> c(N);
	queue<int> Q;
	Q.push(r);
	while (!Q.empty()){
		int v = Q.front();
		Q.pop();
		for (auto P : E[v]){
			int w = P.second;
			if (c[w].empty()){
				c[v].push_back(make_pair(P.first, w));
				Q.push(w);
			}
		}
	}
	return c;
}
int main(){
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < n - 1; i++){
    int s, t, w;
    cin >> s >> t >> w;
    E[s].push_back(make_pair(w, t));
    E[t].push_back(make_pair(w, s));
  }
  vector<vector<pair<int, int>>> c = child(E, 0);
  rerooting<int> ans(c, add, root, 0);
  for (int i = 0; i < n; i++){
    cout << ans[i] << endl;
  }
}
