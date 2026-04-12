#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	bool edges[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			edges[i][j] = false;
		}
	}
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		edges[a-1][b-1] = true;
		edges[b-1][a-1] = true;
	}

	vector<int> perm;
	for(int i = 1; i < n; i++)
		perm.push_back(i);

	int ans = 0;
	do{
		bool able = edges[0][perm[0]];
		for(int i = 0; i < n-2; i++){
			if(!edges[perm[i]][perm[i+1]])
				able = false;
		}
		if(able){
		/*	cout << 0 << " ";
			for(int i = 0; i < n-1; i++)
				cout << perm[i] << " ";
			cout << "\n";*/
			ans++;
		}
	}while(next_permutation(perm.begin(), perm.end()));

	cout << ans << "\n";

	return 0;
}
