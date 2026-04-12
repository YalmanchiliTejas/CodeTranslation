#include<stdio.h>
	int main(){
		char S[3];
		
		scanf ("%s", &S);
		
		if (S[0]==S[2] && S[1]==S[2]){
			puts("No");
		}else  {
			puts("Yes");
		}
		return 0;
	}
