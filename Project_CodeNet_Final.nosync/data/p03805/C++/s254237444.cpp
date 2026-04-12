#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1<<30

int main(){
	int n, m, a, b;
	cin >> n >> m;
	vector<int> per;
	int G[10][10] = {0};
	for(int i = 0;i < n; i++){
		per.pb(i);
	}
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--;b--;
		G[a][b] = 1;
		G[b][a] = 1;
	}
	int cnt = 0;
	do{
		if(per[0] != 0) break;
		int flag = 1;
		for(int i = 0; i < n-1; i++){
			if(G[per[i]][per[i+1]])continue;
			flag = 0;
			break;
		}
		if(flag) cnt++;
	}while(next_permutation(all(per)));
	cout << cnt << endl;
	return 0;
}
