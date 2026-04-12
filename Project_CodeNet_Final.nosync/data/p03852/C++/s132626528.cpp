#include <iostream>

using namespace std;

int main()
{
	char c;
	string vo("aiueo");
	
	cin >> c;
	
	if ((int)vo.find(c) != -1) {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
	
	return (0);
}