#include<stdio.h>

int main(){
	int a=0;
	char A[5];
	for (int i = 0; i < 5; i++) {
		scanf("%c\n", &A[i]);
	}
	
	for(int i = 0; i < 5; i++) {
		if (A[i] =='A' &&A[i + 1]=='C') {
			a = 1;
		
		}
	}
	if (a == 1) {
		printf("Yes");

	}
	else {
		printf("No");
	}
}