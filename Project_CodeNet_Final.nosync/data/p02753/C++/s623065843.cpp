#include<stdio.h>
int main()
{
	char a, b, c;
	scanf("%c %c %c", &a, &b, &c);
	if((a==b && a!=c) || (b==c && b!=a) || (a==c && c!=b)){
		printf("Yes\n");
	}	
	else{
		printf("No\n");
	}
	return 0;
}