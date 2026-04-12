#include <iostream>
using namespace std;

int main()
{
	char x;
	cin>>x;
	switch (x)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		cout<<"vowel \n";
		break;
	default :
		cout<<"consonant \n";
	}
return 0;
}