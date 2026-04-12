#include<bits/stdc++.h>

using namespace std;

int n, m;
char a[101][101];
	
int main() {

	cin>>n>>m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin>>a[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		int br=0;
		for (int j=0; j<m; j++) {
			if (a[i][j]=='.' || a[i][j]=='0') {
				br++;
			} 
		}
		if (br==m) {
			for (int j=0; j<m; j++) {
				a[i][j]='0';
			}
		}
	}
	for (int i=0; i<m; i++) {
		int br=0;
		for (int j=0; j<n; j++) {
			if (a[j][i]=='.' || a[j][i]=='0') {
				br++;
			}
		}
		if (br==n) {
			for (int j=0; j<n; j++) {
				a[j][i]='0';
			}
		}
	}
	for (int i=0; i<n; i++) {
		int br=0;
		for (int j=0; j<m; j++) {
			if (a[i][j]!='0') {
				br++;
				cout<<a[i][j];
			}
		}
		if (br!=0) cout<<endl;
	}
	
}