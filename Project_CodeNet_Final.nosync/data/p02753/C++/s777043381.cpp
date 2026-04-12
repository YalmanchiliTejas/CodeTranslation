#include <stdio.h>

int main (){

	char a,b,c;
	
	scanf("%c%c%c",&a,&b,&c);
	
	(a==b && b==c && a==c) ? puts("No") : puts("Yes");
	
return 0;
}
