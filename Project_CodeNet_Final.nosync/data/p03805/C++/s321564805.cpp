#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 10;
int g[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	memset(g, 0, sizeof(g));
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		u--; v--;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	vector<int> perm(n);
	for(int i = 0; i < n; i++){
		perm[i] = i;
	}
	int ans = 0;
	while(true){
		bool flg = true;
		for(int i = 1; i < n; i++){
			if(!g[perm[i - 1]][perm[i]])flg = false;
		}
		if(flg)ans++;
		if(!next_permutation(perm.begin() + 1, perm.end()))break;
	}
	cout<<ans<<endl;


	return 0;
}