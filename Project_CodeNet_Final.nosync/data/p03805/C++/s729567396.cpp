#include <bits/stdc++.h>
using namespace std;

bool edge[9][9];
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		edge[a][b] = edge[b][a] = true;
	}
	int ans = 0;
	vector<int> v(n);
	for(int i = 0; i < n; i++) v[i] = i+1;
	do {
		if(v[0] != 1) continue;
	    bool ok = true;
	    for(int i = 0; i < n-1; i++){
	    	if(!edge[v[i]][v[i+1]]) ok = false;
	    }
	    if(ok) ans++;
	} while(next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}