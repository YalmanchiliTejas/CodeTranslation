#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
static const int MAX = 200000;

int main()
{
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}



    return 0;
}