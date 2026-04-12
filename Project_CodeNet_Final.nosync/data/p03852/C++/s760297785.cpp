#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define rep(i, n)for((i) = 0;(i) < (n);++(i))

bool f(char c){
	if(c == 'a')return true;
	if(c == 'i')return true;
	if(c == 'o')return true;
	if(c == 'u')return true;
	if(c == 'e')return true;
	return false;
}
int main(void){
	char c;
	scanf("%c", &c);
	puts(f(c) ? "vowel" : "consonant");
	
	return 0;
}