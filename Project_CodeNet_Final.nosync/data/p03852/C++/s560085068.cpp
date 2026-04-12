#include <stdio.h>
int main(){
	char al,a,e,i,o,u;
	scanf("%c",&al);
	if(al == 'a' || al == 'e' || al == 'i' || al == 'o' || al == 'u'){
     printf("vowel\n");
	}
	else
		printf("consonant\n");
	return 0;
}