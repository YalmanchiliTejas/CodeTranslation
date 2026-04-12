#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
char a;
int main(){
	cin>>a;
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') printf("vowel");
	else printf("consonant");
}