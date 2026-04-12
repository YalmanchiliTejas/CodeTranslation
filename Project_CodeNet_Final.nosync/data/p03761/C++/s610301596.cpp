#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
char s[55][55];
int cnt[55][30];
int n;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= strlen(s[i] + 1); j++)
			cnt[i][s[i][j] - 'a']++;
	}
	for(int i = 0; i < 26; i++) cnt[0][i] = 1 << 30;
	for(int i = 0; i < 26; i++){
		for(int j = 1; j <= n; j++)
			cnt[0][i] = min(cnt[0][i], cnt[j][i]);
	}
	for(int i = 0; i < 26; i++){
		while(cnt[0][i]--) printf("%c", i + 'a');
	}
	return 0;
}

