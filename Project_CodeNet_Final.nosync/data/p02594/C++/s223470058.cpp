#include<stdio.h>
int main (){
	int suhu;
	
	-40<=suhu<=40;
	
	scanf("%d", &suhu);
	
	suhu>=30 ? printf("Yes") : printf("No");
	
	return 0;
}