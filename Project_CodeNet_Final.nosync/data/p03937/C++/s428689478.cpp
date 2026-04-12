#include <bits/stdc++.h>

using namespace std;

int D[11][11];
char str[11][11];
int n,m,cnt;

int main()
{
	int i,j;
	
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++){
		scanf("%s",str[i]);
		for(j=0;j<m;j++) cnt += str[i][j] == '#';
	}
	
	if(cnt != n+m-1){
		printf("Impossible\n");
		return 0;
	}
	
	D[0][0] = 1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++) if(str[i][j] == '#'){
			if(i) D[i][j] += D[i-1][j];
			if(j) D[i][j] += D[i][j-1];
		}
	}
	
	printf("%s\n",D[n-1][m-1] == 1? "Possible" : "Impossible");
	
	return 0;
}