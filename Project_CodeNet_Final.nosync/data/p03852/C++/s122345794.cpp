#include<bits/stdc++.h>
using namespace std;

string s = "aeiou";
int main(){
	char buf[2];
	scanf("%s", buf);
	if (s.find(buf[0]) != string::npos){
		puts("vowel");
	}
	else{
		puts("consonant");
	}
	return 0;
}