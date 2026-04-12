#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void a_iai(void) {
	char c;
	cin >> c;
	string judge = "vowel";
	if ((c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u')) judge = "consonant";
	cout << judge << endl;
}

int main()
{
	a_iai();
    return 0;
}