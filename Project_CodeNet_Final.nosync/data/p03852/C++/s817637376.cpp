#include<bits/stdc++.h>
using namespace std;
char s[5];
int main(){
	scanf("%s",s);
	if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u'){
		printf("vowel");
	}else printf("consonant");
}