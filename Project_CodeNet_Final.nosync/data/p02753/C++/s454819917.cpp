#include<stdio.h>

int main(){
	char S[3];
	
	scanf("%s",S);
	
	for(int i=0;i<2;i++){
		if(S[i] == 'A'){
			if(S[i+1] == 'B'){
				printf("Yes\n");
				return 0;
			}
		}else if(S[i] == 'B'){
			if(S[i+1] == 'A'){
				printf("Yes\n");
				return 0;
			}
		}
	}
	
	printf("No\n");
		
	return 0;
}