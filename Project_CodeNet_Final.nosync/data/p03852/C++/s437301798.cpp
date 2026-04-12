#include <iostream>

using namespace std;

char c;
char v[] = {'a', 'i', 'u', 'e', 'o'};

int main(void)
{
	cin >> c;
	for(int i = 0; i < 5; i++) if(c == v[i]){
		cout << "vowel" << endl;
		return 0;
	}
	cout << "consonant" << endl;
	return 0;
}