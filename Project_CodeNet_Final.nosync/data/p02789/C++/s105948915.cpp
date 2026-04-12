#include<stdio.h>
	int main(){
		int N,M;
		
		scanf("%d",&N);
		getchar();
		scanf ("%d", &M);
		getchar();
		
		if ( N <= M){
			printf ("Yes\n");
		}else {
			printf ("No\n");
		}	
		return 0;
	}
