#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string s;

int main() {
	cin >> s;

	if (s[0] == s[1] && s[1] == s[2])
		puts("No");
	else
		puts("Yes");

	return 0;
}