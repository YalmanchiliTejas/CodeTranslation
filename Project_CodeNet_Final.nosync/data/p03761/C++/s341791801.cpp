#include <cstdio>
#include <cstring>
int main (){
	int n, len, cnt[50][26] = {0}, low;
	char s[51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", s);
		len = strlen(s);
		for (int j = 0; j < len; j++)
			cnt[i][s[j] - 'a']++;
	}
	for (int i = 0; i < 26; i++){
		low = cnt[0][i];
		for (int j = 1; j < n; j++){
			if (low > cnt[j][i])
				low = cnt[j][i];
		}
		for (int j = 0; j < low; j++)
			printf("%c", i + 'a');
	}
	printf("\n");
	return 0;
}