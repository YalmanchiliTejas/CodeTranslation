#include <bits/stdc++.h>

using namespace std;

#define INF 1000000009
#define INP "input.txt"
#define OUT "output.txt"

int n, m;
char arr[10][10];

bool solution() {
	int cnt = 0;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == '#') cnt++;
		}	
	if(cnt != n + m - 1) return false;

	int i, j;
	i = j = 0;
	if(arr[i][j] != '#') return false;

	while(i != n - 1 && j != m - 1) {
		if(i + 1 < n && arr[i + 1][j] == '#') i++;
		else if(j + 1 < m && arr[i][j + 1] == '#') j++;
		else return false;
	}
	return true;
}

int main () {
	 //freopen(INP, "r", stdin);
	 //freopen(OUT, "w", stdout);

	 scanf(" %d %d ", &n, &m);
	 for(int i = 0; i < n; i++) {
	 	scanf("%s", &arr[i]);
	 }

	 if(solution()) printf("Possible\n");
	 else printf("Impossible\n");

	return 0;
}