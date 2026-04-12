#include <stdio.h>

int main (){
	int input[100];
	for (int a=0;a<3;a++){
		scanf ("%d",&input[a]);
	}
	int total=input[0]*100+input[1]*10+input[2];
//	printf ("%d",total);
	if (total%4==0){
		printf ("YES\n");
	}else printf ("NO\n");

}
