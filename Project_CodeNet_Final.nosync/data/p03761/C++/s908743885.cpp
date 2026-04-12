#include <cstdio>
#define MAXN 55
#define INF 0x7fffffff
int a[MAXN][26];
char temp[MAXN];

int main() {
	int n, mn;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", temp);
		for(int j = 0; temp[j] != '\0'; j++) 
			a[i][temp[j] - 'a']++;
	}
	for(int i = 0; i < 26; i++) {
		mn = INF;
		for(int j = 0; j < n; j++) {
			if(a[j][i] == 0) {
				mn = 0;
				break;
			}
			if(a[j][i] < mn) mn = a[j][i];
		}
		for(int j = 0; j < mn; j++)
			printf("%c", i+'a');
	}	
	return 0;
} 