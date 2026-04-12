#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;

int main(){
	char c;
	cin >> c;
	
	if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
		printf("vowel\n");
	}else{
		printf("consonant\n");
	}
	
	return 0;
}