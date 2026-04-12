#include <stdio.h>

int main()
{
	char a, b, c;
	scanf("%c%c%c", &a, &b, &c);
	
	if(a==b && b!=c || a==c && c!=b || b==c && c!=a){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}