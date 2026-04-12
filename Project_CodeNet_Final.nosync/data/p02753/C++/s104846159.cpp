#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
string s;
int cnt;
int main() {
	cin >> s;
	if (s[0] == 'A') cnt++;
	if (s[1] == 'A') cnt++;
	if (s[2] == 'A') cnt++;
	if (cnt == 0 || cnt == 3) {
		puts("No");
	} else {
		puts("Yes");
	}
	return 0;
} 