#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	int k;
	scanf("%d", &n);
	cin >> s;
	scanf("%d", &k);
	
	char c = s[k - 1];
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != c) s[i] = '*';
	}

	cout << s << endl;
}