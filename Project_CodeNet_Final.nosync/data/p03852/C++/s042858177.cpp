#include <iostream>
using namespace std;
string solve(char c, string vowel)
{
	for(int i = 0; i < vowel.size(); i++)
		if( c == vowel[i] )
			return "vowel";
	return "consonant";
}
int main()
{
	char c;
	cin >> c;
	string vowel = "aeiuo";
	cout << solve(c,vowel);
}
