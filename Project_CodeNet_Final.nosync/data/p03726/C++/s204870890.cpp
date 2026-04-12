#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAXN = 200005;
const int MOD = 1000000007;

vector<int> g[MAXN];
int d[MAXN],c[MAXN],pa[MAXN];
set<pair<int,int>> s;

void dfs(int a,int p){
	pa[a] = p;
	for(int i:g[a]) if(i != p) dfs(i,a);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for(int i=0;i<n-1;i++){
		int a,b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		d[a]++;
		d[b]++;
	}
	dfs(n,0);
	for(int i=1;i<=n;i++) s.insert({d[i],i});
	while(!s.empty()){
		auto t = *s.begin(); s.erase(s.begin());
		int a = t.second;
		if(a == n){
			c[a] = 1; break;
		}
		if(c[pa[a]] != 0){
			cout << "First\n"; return 0;
		}
		c[a] = 2; c[pa[a]] = 1;
		s.erase({d[pa[a]],pa[a]});
		int grand = pa[pa[a]];
		if(grand == 0 || c[grand] != 0) continue;
		s.erase({d[grand],grand});
		d[grand]--;
		s.insert({d[grand],grand});
	}
	for(int i=1;i<=n;i++) if(c[i] == 1){
		int f = 0;
		for(int j:g[i]) if(c[j] == 2){
			f = 1; break;
		}
		if(f == 0){
			cout << "First\n"; return 0;
		}
	}
	cout << "Second\n";
	return 0;
}
