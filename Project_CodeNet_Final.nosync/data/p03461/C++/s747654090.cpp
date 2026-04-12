#include <bits/stdc++.h>
using namespace std;
const int maxn = 111;
int d[maxn][maxn]; // d[x][y] = min x * a + y * b + f[a][b]
int f[maxn][maxn]; // f[a][b] = max x * a + y * b - d[x][y]
int S[maxn], T[maxn];
int main(){
	int A, B;
	cin >> A >> B;
	for(int x = 1; x <= A; x++){
		for(int y = 1; y <= B; y++){
			cin >> d[x][y];
			for(int a = 0; a < maxn; a++){
				for(int b = 0; b < maxn; b++){
					f[a][b] = max(f[a][b], -(x * a + y * b - d[x][y]));
				}
			}
		}
	}
	for(int x = 1; x <= A; x++){
		for(int y = 1; y <= B; y++){
			int mi = 1<<30;
			for(int a = 0; a < maxn; a++){
				for(int b = 0; b < maxn; b++){
					mi = min(mi, x * a + y * b + f[a][b]);
				}
			}
			if(mi != d[x][y]){
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << "Possible" << endl;
	int nds = 1;
	for(int i = 0; i < maxn; i++){
		S[i] = nds++;
		T[i] = nds++;
	}
	cout << 2 * maxn << " " << 2 * maxn - 2 + maxn * maxn << endl;
	for(int i = 0; i < maxn - 1; i++){
		cout << S[i] << " " << S[i + 1] << " X" << endl;
	}
	for(int i = maxn - 1; i > 0; i--){
		cout << T[i] << " " << T[i - 1] << " Y" << endl; 
	}
	for(int a = 0; a < maxn; a++){
		for(int b = 0; b < maxn; b++){
			cout << S[a] << " " << T[b] << " " << f[a][b] << endl;
		}
	}
	cout << S[0] << " " << T[0] << endl;
	return 0;
}
