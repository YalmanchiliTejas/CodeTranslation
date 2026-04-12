#include<stdio.h>

int main(){
	char a, b, c;
	
	scanf("%c %c %c",&a, &b, &c);
	
	if ((a==b && a!=c)||(a==c && a!=b)||(b==c && b!=a)){
	printf ("Yes\n");
	
	}else
	printf ("No\n");
	return 0;
}