#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (s[i] != s[j]) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}