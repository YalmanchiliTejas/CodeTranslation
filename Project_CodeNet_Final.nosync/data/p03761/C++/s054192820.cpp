#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n, b[55][55], c[30];
char a[55][55];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < 26; i++)
		c[i] = 100000;
	for(int i = 1; i <= n; i++){
		getchar();
		scanf("%s", a[i]);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < strlen(a[i]); j++){
			b[i][a[i][j] - 'a']++;
		}
	for(int j = 0; j < 26; j++)
		for(int i = 1; i <= n; i++)
			c[j] = min(c[j], b[i][j]);
	for(int i = 0; i < 26; i++)
		for(int j = c[i]; j > 0; j--)
			printf("%c", (i + 'a'));
	printf("\n");
}