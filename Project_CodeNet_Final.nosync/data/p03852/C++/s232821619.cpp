#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

char ch;

void init(){
	
	scanf("%c", &ch);
	if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {
		printf("vowel\n");
	}
	else {
		printf("consonant\n");
	}
}

int main(){
	
	init();
	return 0;
}