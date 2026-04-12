#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string vec[105];
int is_col_ok[105];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++){
		cin >> vec[i];
		for (j = 0; j < m; ++j)
			if (vec[i][j] != '.')
				break;
		if (j == m){
			--i;
			--n;
		}
	}
	int k;
	for (j = 0; j < m; j++){
		for (i = 0; i < n; i++){
			if (vec[i][j] != '.')
				break;
		}
		if (i == n){
			is_col_ok[j] = 1;
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			if (is_col_ok[j] == 0)
				printf("%c", vec[i][j]);
		}
		printf("\n");
	}
	return 0;
}