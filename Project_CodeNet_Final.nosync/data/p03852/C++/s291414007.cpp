
#include <iostream>
using namespace std;
int main()
{
	char O;
	cin >> O;
	if (O == 'a' || O == 'e' || O == 'i' || O == 'o' || O == 'u')
	{
		cout << "vowel" << endl;
	}
	else cout << "consonant" << endl;
}