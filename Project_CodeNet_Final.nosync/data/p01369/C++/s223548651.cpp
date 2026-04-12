#include <iostream>
#include <cstring>
using namespace std;

int judge(char s) {
	if ((s == 'y' )|| (s == 'u') || (s == 'i') || (s == 'o') || (s == 'p') || (s == 'h') || 
		(s == 'j') || (s == 'k') || (s == 'l') || (s == 'n') || (s == 'm'))return 1;
	else 	return 0;
};

int main()
{
	char s[33];
		for (; cin >> s , s[0] != '#';)
		{
			int count = 0;
			for (int i = 0; i+1 < strlen(s); i++)
			{
				if(!(judge(s[i]) == judge(s[i+1])))count++;
			}
			cout << count << endl;
		}
	return 0;
}