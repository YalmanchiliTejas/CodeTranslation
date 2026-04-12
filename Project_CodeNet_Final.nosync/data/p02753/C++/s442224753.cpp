#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void){
	char s[3];
	scanf("%s",s);
	char m=s[0];
	for(int n=0;n<3;n++){
		if(s[n]!=m){
			printf("Yes");
			return 0;
		}
		m=s[n];
	}
	printf("No");
	return 0;
}