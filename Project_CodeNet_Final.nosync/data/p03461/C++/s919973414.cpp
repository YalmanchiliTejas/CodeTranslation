#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 303, M = 100;
int a, b, d[14][14], C[M+3][M+3], sz = 1;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b;
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++)
			cin >> d[i][j];
	for(int as = 0; as <= M; as++) {
		for(int bs = 0; bs <= M; bs++) {
			int mn = 0;
			for(int i =1; i <= a; i++)
				for(int j = 1; j <= b; j++)
					mn = max(mn, d[i][j] - as*i - bs*j);
			C[as][bs] = mn;
		}
	}
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++) {
			int cst = 1<<30;
			for(int as = 0; as <= M; as++)
				for(int bs = 0; bs <= M; bs++)
					cst = min(cst, as*i + bs*j + C[as][bs]);
			if(cst != d[i][j]) return cout << "Impossible\n", 0;
		}
	
	cout << "Possible\n";
	cout << 2*M+2 << " " << (M+1)*(M+1) + 2*M << '\n';
	for(int i = 1; i <= M; i++)
		cout << sz << " " << sz+1 << " X\n", sz++;
	sz++;
	for(int i = 1; i <= M; i++)
		cout << sz << " " << sz+1 << " Y\n", sz++;
	for(int i = 0; i <= M; i++)
		for(int j = 0; j <= M; j++)
			cout << 1+i << " " << M+2+j << " " << C[i][M-j] << '\n';
	cout << 1 << " " << 2*M+2 << '\n';
}
