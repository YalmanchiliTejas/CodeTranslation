#include<stdio.h>

int main(){
	char a[7];
	
	scanf("%s", a);
	if ((a[0]==a[1]&&a[0]!=a[2])||(a[2]==a[1]&&a[0]!=a[2])||
	(a[0]==a[2]&&a[1]!=a[2])){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}