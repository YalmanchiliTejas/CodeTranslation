#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
	char s[233];
	scanf("%s", s+1);
	for (int i=1; i<strlen(s+1); i++) {
		if (s[i]=='A' && s[i+1]=='C') {
		   cout<<"Yes"<<'\n';
		   return 0;
		}
	}
	cout<<"No"<<'\n';
}