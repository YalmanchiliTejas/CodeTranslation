#include<iostream>
#include <math.h>
#include<vector>
#include<algorithm>
using namespace std;
char a;
int main() {
	cin >> a;
	if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o')cout << "vowel" << endl;
	else cout << "consonant" << endl;

	return 0;
}