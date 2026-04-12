#include<cstdio>

int n, id;
char s[111];

int main() {
	scanf("%d%s%d", &n, s, &id);
	id--;
	for(int i=0;i<n;i++)
		if(s[i]!=s[id]) s[i] = '*';
	printf("%s\n", s);
	
	return 0;
}