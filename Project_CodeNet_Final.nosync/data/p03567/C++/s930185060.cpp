#include <stdio.h>
#include <string.h>
int main(void)
{
	int i;
	char s[6];
	scanf("%s",s);
	for(i=0; i<strlen(s)-1; i++){
		if(s[i]=='A' && s[i+1]=='C'){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}