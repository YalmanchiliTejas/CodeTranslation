#include<stdio.h>
int main()
{
	char a[3];
	scanf("%s",a);
	if(a[0]==a[1]&&a[0]!=a[2]&&a[1]!=a[2]){
		printf("Yes");
	}
	else if(a[0]==a[2]&&a[0]!=a[1]&&a[2]!=a[1]){
		printf("Yes");
	}
	else if(a[1]==a[2]&&a[1]!=a[0]&&a[2]!=a[0]){
		printf("Yes");
	}
	else if(a[0]==a[2]&&a[0]==a[1]&&a[1]==a[2]){
		printf("No");
	}
	return 0;
}