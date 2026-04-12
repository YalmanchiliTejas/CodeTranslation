#include<stdio.h>
#include<string.h>
int main() {
	char s[5];
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='A' && s[i+1]=='C'){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}