#include <bits/stdc++.h>

using namespace std;

int A, B, N, M, S, T, d[15][15];
int adj[102][102];
int dist[204];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("output.txt","w",stdout);
	cin >> A >> B;
	for (int i = 1; i <= A; ++i){
		for (int j = 1; j <= B; ++j){
			cin >> d[i][j];
		}
	}
	S = 1;
	T = 202;
	for (int i = 0; i <= 100; ++i){
		for (int j = 0; j <= 100; ++j){
			int maxi = 0;
			for (int k = 1; k <= A; ++k){
				for (int l = 1; l <= B; ++l){
					maxi = max(maxi,d[k][l]-k*i-j*l);
				}
			}
			adj[i][j] = maxi;
			if (maxi > 100){
				cout << "Impossible\n";
				return 0;
			}
		}
	}
	for (int k = 1; k <= A; ++k){
		for (int l = 1; l <= B; ++l){
			dist[1] = 0;
			for (int i = 1; i <= 100; ++i){
				dist[i+1] = dist[i] + k;
			}
			for (int i = 0; i <= 100; ++i){
				int mini = 1e9;
				for (int j = 0; j <= 100; ++j){
					mini = min(mini,adj[j][100-i]+dist[j+1]);
				}
				if (i > 0){
					mini = min(mini,dist[102+i-1]+l);
				}
				dist[102+i] = mini;
			}
			//cout << dist[202] << ' ';
			if (dist[202] != d[k][l]){
				cout << "Impossible\n";
				return 0;
			}
		}
		//cout << '\n';
	}
	N = 202;
	M = 100+100+(101*101);
	cout << "Possible\n";
	cout << N << ' ' << M << '\n';
	for (int i = 1; i <= 100; ++i){
		cout << i << ' ' << i+1 << ' ' << 'X' << '\n';
	}
	for (int i = 102; i <= 201; ++i){
		cout << i << ' ' << i+1 << ' ' << 'Y' << '\n';
	}
	for (int i = 0; i <= 100; ++i){
		for (int j = 0; j <= 100; ++j){
			cout << i+1 << ' ' << j+102 << ' ' << adj[i][100-j] << '\n';
		}
	}
	cout << S << ' ' << T << '\n';
	cout << flush;
	//for (int i = 1; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
}