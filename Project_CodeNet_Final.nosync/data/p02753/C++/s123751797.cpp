#include <stdio.h>

int main(void){

	int i;
	int x1 = 0, x2 = 0;
	char S[3];

	for(i = 0; i < 3; i++){
		scanf("%s", &S[i]);
		if(S[i] == 'A')
			x1++;
		if(S[i] == 'B')
			x2++;
	}
	if((x1 == 3) ||(x2 == 3))
		printf("No");
	else
	  printf("Yes");

  return 0;
}
