#include<stdio.h>
int main()
{
	int N, k;
	scanf("%d", &N);
	
	int H[N];
	
	for(k=0; k<N; k++){
		scanf("%d", &H[k]);
	}
	
	int max = 0;
	int c = 0;
	
	for(k=0; k<N; k++){
		if(H[k] >= max){
			max = H[k];
			c++;
		}
	}
		
	printf("%d", c);
	
	return 0;
	
}