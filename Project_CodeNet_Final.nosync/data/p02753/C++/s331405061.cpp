#include <stdio.h>

int main(){
	char S[3];
	scanf("%c%c%c",&S[0],&S[1],&S[2]);
	if (S[0] == S[1]&&S[1] == S[2]){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	return 0;
}