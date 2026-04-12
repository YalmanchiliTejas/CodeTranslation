#include <stdio.h>

int main(void) {
	char a, b, c;
	scanf("%c%c%c", &a, &b, &c);
	if(a != b){
		printf("Yes");
	}
	else if(a != c){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}