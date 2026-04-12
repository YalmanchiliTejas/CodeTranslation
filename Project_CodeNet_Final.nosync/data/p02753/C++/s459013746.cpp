#include <stdio.h>
int main(){
	char A[3];
	scanf("%s", A);
	if(A[0]==A[1]&&A[0]!=A[2]&&A[1]!=A[2]){
		puts("Yes");
	} else if(A[0]==A[2]&&A[0]!=A[1]&&A[2]!=A[1]){
		printf("Yes");
	} else if(A[1]==A[2]&&A[1]!=A[0]&&A[2]!=A[0]){
		printf("Yes");
	} else if(A[0]==A[2]&&A[0]==A[1]&&A[1]==A[2]){
		printf("No");
	} 
	return 0;

}