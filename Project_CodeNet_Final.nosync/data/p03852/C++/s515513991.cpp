#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c){
	return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
}
int main() {
	// your code goes here
	string s;
	cin>>s;
	printf("%s\n", isVowel(s[0]) ? "vowel" : "consonant");
	return 0;
}