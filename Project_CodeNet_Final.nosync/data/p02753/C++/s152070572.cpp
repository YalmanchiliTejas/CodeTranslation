#include<stdio.h>

int main (){
	
	char i = 'A', j = 'A', x = 'B';
	scanf("%c %c %c", &i, &j, &x);
	
	if(i == j && j == x && i == x){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}