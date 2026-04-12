#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 13;
int n, sz[maxN], cur[maxN];
bool win;
vector<int> adj[maxN];
void dfs (int x, int par) {
    sz[x] = 1;
    for (auto a : adj[x]) {
	if (a != par) {
	    dfs(a, x);
	    sz[x] += sz[a];
	    if (sz[a] % 2 == 1)
		cur[x]++;
	}
    }
    if (cur[x] >= 2)
	win = 1;
}

int main () {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
	int a, b;
	cin >> a >> b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    if (n % 2 == 1) 
	return cout << "First" << endl, 0;
      
    dfs(1, 1);
    if (win)
	cout << "First" << endl;
    else
	cout << "Second" << endl;
}
