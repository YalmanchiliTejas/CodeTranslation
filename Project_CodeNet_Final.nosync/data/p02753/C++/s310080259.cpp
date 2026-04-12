#include <stdio.h>

int main(){
	char a1, a2, a3;
	scanf("%c %c %c", &a1, &a2, &a3);
	if (a1, a2 != a3){
		printf("Yes\n");
	}
	else if (a1, a3 != a2){
		printf("Yes\n");
	}
	else if (a2, a3 != a1){
		printf("Yes\n");
	}
	else if (a1 == a2, a2 == a3){
		printf("No\n");
	}
	
	return 0;
}