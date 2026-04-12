#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	char ch; cin >> ch;
	if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u') cout << "vowel" << endl;
	else cout << "consonant" << endl;
}