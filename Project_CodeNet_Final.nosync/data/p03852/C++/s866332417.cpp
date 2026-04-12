// UOIAUAI

#include <iostream>

using namespace std;

int main(){
	char c;
	char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
	cin >> c;

	bool flag = false;
	for (int i = 0; i < 5; ++i)
		if (vowel[i] == c){
			flag = true;
			break;
		}

	if (flag)
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;

	return 0;
}