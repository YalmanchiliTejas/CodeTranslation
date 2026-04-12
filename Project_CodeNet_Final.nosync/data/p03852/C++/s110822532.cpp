#include <utility>
#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define YES(b) std::cout<< (b ? "Yes" : "No")
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	char s;
	cin >> s;
	if (s == 'a' || s == 'i' || s == 'e' || s == 'o' || s == 'u') {
		cout << "vowel";
		return 0;
	}
	cout << "consonant";
}
