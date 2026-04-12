#include<stdio.h>
int main(){
	char a, b, c;
	scanf("%c%c%c", &a, &b, &c);
	if(a==b && a!=c){
		puts("Yes");
	}
	else if(c==b && a!=c){
		puts("Yes");
	}
	else if(a==c && a!=b){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}