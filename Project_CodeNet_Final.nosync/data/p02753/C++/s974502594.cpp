#include <stdio.h>
#include <string.h>
int main(){
	char input[21];
	int check = 0;

	scanf("%s", input);
	if(input[0] == input[1] && input[1] == input[2] && input[2] == input[0]){printf("No");}
	else{printf("Yes");}
	
	return 0;
}