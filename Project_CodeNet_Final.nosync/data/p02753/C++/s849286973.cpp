#include<stdio.h>
int main(){
	
	char S1;
	char S2;
	char S3;
	
		scanf("%c %c %c",&S1,&S2,&S3);
			if(S1==S2,S1!=S3,S2!=S3){
				puts("Yes");
			}
	        else if(S1==S3,S1!=S2,S3!=S2){
	        	puts("Yes");
			}
	        else if(S2==S3,S1!=S2,S1!=S3){
	        	puts("Yes");
			}
	        else {
	        	puts("No");
			}
	return 0;
}