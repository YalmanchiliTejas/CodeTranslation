#include<cstdio>
int main(){
	char a[100][101];
	bool b[100];
	bool c[100];
	int n, m;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++)b[i] = false;
	for (int i = 0; i < m; i++)c[i] = false;
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
		for (int j = 0; j < m; j++){
			if (a[i][j] == '#'){
				b[i] = true;
				c[j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (b[i]){
			for (int j = 0; j < m; j++){
				if (c[j])printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}