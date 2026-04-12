#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	char c;
	cin >> c;
	set<char>a = {'a','e','i','o','u'};
	if (a.count(c))cout << "vowel" << endl;
	else cout << "consonant" << endl;
}
