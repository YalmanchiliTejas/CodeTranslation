#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

#define ll long long
#define PII pair<int ,int>

using namespace std;

int main() {
	char a; cin >> a;
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') cout << "vowel\n";
	else cout << "consonant\n";
	return 0;
}