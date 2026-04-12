#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string A;
	cin >> A;
	string ans = "consonant";
	char s[5] = { 'a', 'i', 'u', 'e', 'o' };
	for (int i = 0; i <= A.length(); i++)
	{
		for (int n = 0; n < 5; n++)
		{
			if(s[n] == A[i])
			{
				ans = "vowel";

			}
		}

	}
	cout << ans << endl;
	return 0;
}