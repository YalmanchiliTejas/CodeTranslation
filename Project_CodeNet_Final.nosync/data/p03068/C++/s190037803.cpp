#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
string s;
int main() {
	cin >> n >> s >> k;
	for(int i=0; i<n; i++) {
		putchar(s[i]==s[k-1] ? s[i] : '*');
	}
	return 0;
}