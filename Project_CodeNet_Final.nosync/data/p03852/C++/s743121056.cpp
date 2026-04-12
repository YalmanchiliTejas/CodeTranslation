#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;


int main()
{
	char a;
	cin >> a;
	string v = "aiueo";
	if (v.find(a) < 5) {
		cout << "vowel" << endl;
	}
	else
		cout << "consonant" << endl;
	return 0;
}