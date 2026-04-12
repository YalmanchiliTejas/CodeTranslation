#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	char c=getchar();
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')printf("vowel\n");
	else printf("consonant\n");
	return 0;
}