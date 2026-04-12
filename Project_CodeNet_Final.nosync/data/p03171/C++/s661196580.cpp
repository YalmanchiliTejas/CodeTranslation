#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bd[3001][3001], n, a;

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a;
		bd[i][i] = a;
	}
	for (int i=1; i<=n-1; i++) {
		for (int j=0; j+i<n; j++) {
			bd[j][j+i] = max(bd[j][j]-bd[j+1][j+i], bd[j+i][j+i]-bd[j][j+i-1]);		
		}	
	}
	cout << bd[0][n-1] << "\n";
}