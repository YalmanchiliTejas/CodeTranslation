#include <stdio.h>

int main(void){
	char S[3];
	scanf("%s\n",S);
	if(S[0]==S[1] && S[0]==S[2])printf("No");
	else printf("Yes");

    return 0;
}
