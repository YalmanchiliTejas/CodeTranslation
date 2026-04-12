#include<stdio.h>
int main(){
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	if(a==b && a!=c && b!=c){
		printf("Yes");
	}
	if(a==c && a!=b && b!=c){
		printf("Yes");
	}
	if(b==c && a!=b && a!=c){
		printf("Yes");
	}
	else if(a==b && a==c && b==c){
		printf("No");
	}
		return 0;	
}