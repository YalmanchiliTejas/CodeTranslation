#include <iostream>
#include <cstdio>
using namespace std;
char c;
int main(){
	scanf("%c",&c);
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
	    printf("vowel\n");
	else
	    printf("consonant\n");
	return 0;
}