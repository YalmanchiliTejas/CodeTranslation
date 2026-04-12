#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 60;
int n, b[MAXN][26];
int a[MAXN];
char s[MAXN];

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%s", s);
		int l = strlen(s);
		for(j = 0; j < l; j++) b[i][s[j]-'a']++;
	}
	for(i = 0; i < 26; i++) a[i] = 10000;
	for(i = 1; i <= n; i++) 
		for(j = 0; j < 26; j++) a[j] = min(a[j], b[i][j]);
	for(i = 0; i < 26; i++) 
		while(a[i]--) printf("%c", i+'a');
	return 0;
}
