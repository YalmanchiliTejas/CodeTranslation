#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int n; scanf("%d", &n);
	int c[26][50] = {};
	for(int i = 0; i < n; i++){
		char s[51]; scanf("%s", s);
		for(int j = 0; s[j] != '\0'; j++) c[s[j] - 'a'][i]++;
	}
	int res[26];
	for(int i = 0; i < 26; i++) res[i] = *min_element(c[i], c[i] + n);
	for(int i = 0; i < 26; i++) for(int j = 0; j < res[i]; j++) putchar('a' + i);
	puts("");
	return 0;
}