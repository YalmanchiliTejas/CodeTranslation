#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#define n printf("consonant")
#define y printf("vowel")
#define b break
using namespace std;
char a;
int main(){
	cin>>a;
	switch(a){
		case 'a':y;b;
		case 'e':y;b;
		case 'i':y;b;
		case 'o':y;b;
		case 'u':y;b;
		default:n;b;
	}
	
	return 0;
}