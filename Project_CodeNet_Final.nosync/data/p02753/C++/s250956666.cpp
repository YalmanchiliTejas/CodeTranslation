#include <stdio.h>
int main()
{
	char a,b,c;
	scanf("%s%s%s",&a,&b,&c);
	
	if (a==b && a!=c){
		printf("Yes");
	}
	else if(b==c && b!=a){
		printf("Yes");
	}
	else if(c==a && c!=b){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}