#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m;
char str[11][11];

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<i; k++){
				for(int l=j+1; l<m; l++){
					if(str[k][l] == '#' && str[i][j] == '#'){
						puts("Impossible");
						return 0;
					}
				}
			}
		}
	}
	puts("Possible");
}
