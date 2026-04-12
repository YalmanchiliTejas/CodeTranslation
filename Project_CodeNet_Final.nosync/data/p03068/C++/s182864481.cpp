#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

#define ll long long

int main() {
	int n, k;
	char s[100];
	char j;
	cin >> n >> s >> k;
	j = s[k - 1];
	for (int i = 0; i < n; i++) {
		if (s[i] != j)s[i] = '*';
	}
	cout << s << endl;
	return 0;
}