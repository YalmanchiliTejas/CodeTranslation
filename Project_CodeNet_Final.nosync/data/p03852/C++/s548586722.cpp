#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
	string s;
	cin>>s;
	switch(s[0]){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			cout<<"vowel"<<endl;
			return 0;
		default:
			cout<<"consonant"<<endl;
			return 0;
	}
	return 0;
}