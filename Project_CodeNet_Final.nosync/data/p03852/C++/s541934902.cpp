#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

int main() {
	char a; cin >> a;
	if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')puts("vowel");
	else puts("consonant");
}