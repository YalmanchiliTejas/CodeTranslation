#include<iostream>
#include<cstdio>
#include<ctype.h>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
string s="aeiou";
int main() {
	char c=getchar();
	for(int i=0;i<5;++i)if(c==s[i]){puts("vowel");return 0;}
	puts("consonant");
	return 0;
}