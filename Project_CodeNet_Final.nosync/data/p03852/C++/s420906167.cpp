#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	string p;

	cin >> p;

	if (p=="a"||p=="i"||p=="u"||p=="e"||p=="o") {
		cout << "vowel" << endl;
	}

	else{
		cout << "consonant" << endl;
	}

	return 0;
}