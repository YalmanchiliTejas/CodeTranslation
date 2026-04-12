#include<stdio.h>
char x[10];
int main(){
	scanf("%s",x);
	if(x[0]==x[1]&&x[1]==x[2]){
		printf("No");
		return 0;
	}
	printf("Yes");
}