#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int N,M;
    cin >> N >> M;

    int g[10][10] = {};
    for(int i=0; i<M; i++) {
	int a,b;
	cin >> a >> b;
	g[a][b] = 1;
	g[b][a] = 1;
    }
    
    vector<int> a(N-1);
    for(int i=2; i<=N; i++) {
	a[i-2] = i;
    }

    ll ans = 0;
    do{
	int u=1,v = a[0];
	if( g[u][v] != 1 ) continue;
	bool f = true;
	for(int i=1; i<a.size(); i++) {
	    u = v; v = a[i];
	    if( g[u][v] != 1 ) f = false;
	}
	if(f){
	    ans++;
	}
    }while(next_permutation(a.begin(), a.end()));
    cout << ans << endl;
    
    
    
    return 0;
}
