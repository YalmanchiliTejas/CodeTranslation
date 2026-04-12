#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int sinpan;
	int input;
	int score_sum;
	int smax, smin;
	
	while(1){
		scanf("%d", &sinpan);
		if ( sinpan == 0 ) { break; }
		
		score_sum = 0;
		smax = 0;
		smin = 1000;
		
		for ( int i=0; i<sinpan; i++ ) {
			scanf("%d", &input);
			score_sum += input;
			if ( smax < input ) { smax = input; }
			if ( smin > input ) { smin = input; }
		}
		printf("%d\n", (int)( (score_sum-smax-smin)/(sinpan-2)));

	}
	
	return 0;
}