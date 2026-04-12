#include <bits/stdc++.h>
using namespace std;

int n, m;
 
set<pair<int, int>> edges;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; i++){
        cin >> a >> b;
        edges.insert({a, b});
    }
    vector<int> v;
    for (int i = 1; i <= n; i++){
    	v.push_back(i);
    }
    int ans = 0;
    do{
    	int ok = true;
    	for (int i = 0; i < n - 1; i++){
    		int a = min(v[i], v[i + 1]);
    		int b = max(v[i], v[i + 1]);
    		if (edges.find({a,b}) == edges.end()){
    			ok = false; break;	
    		}
    	}
    	if (ok) ans++;
    }while(next_permutation(v.begin() + 1, v.end()));
    cout << ans << endl;
    return 0;
}