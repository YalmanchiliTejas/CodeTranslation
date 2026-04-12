#include<stdio.h>
#include<string.h>
int main(){
	int i;
	char s[10000];
	scanf("%s",s);
	for (i=0;i<strlen(s);i++) {
		if (s[i]=='A'&&s[i+1]=='C') {
			printf("Yes\n");return 0;
		}
	}
	printf("No\n");return 0;
} 