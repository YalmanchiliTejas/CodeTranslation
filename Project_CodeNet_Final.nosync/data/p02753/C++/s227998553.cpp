#include<stdio.h>


 int main(){
 	char S[5];
 	int D = 0;
 	scanf("%s", &S);
 	for(int i = 0; i < S[i]; i++){
 		if(S[i] == S[0] && S[i] == S[1] && S[i] == S[2]){
 			D++;
			 }
		 }
	if(D == 3){
		puts("No");
	}
	else{
		puts("Yes");
	}
	return 0;
	 }
