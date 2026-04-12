///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
const int mx = 1000 * 100 + 5;
vector < int > ad[mx];
bool col[mx];
void dfs(int v, int par){
	for(auto u : ad[v]){
		if(u != par){
			dfs(u , v);
			if(col[u])
				continue;
			else if(col[v]){
				cout << "First" << endl;
				exit(0);
			}
			else
				col[u] = col[v] = 1;
		}
	}
	return;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 	cout.tie(0);
	int n, u, v;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	if(n % 2 == 1){
		cout << "First" << endl;
		return 0;
	}
	col[0] = 1;
	dfs(1 , 0);
	cout << "Second" << endl;
	return 0;
}

