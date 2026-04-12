#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(){
	
	char c;
	scanf("%c",&c);

	if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
		printf("vowel\n");
	}
	else{
		printf("consonant\n");
	}
	
		
	return 0;
}