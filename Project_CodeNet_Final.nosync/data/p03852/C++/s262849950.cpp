#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <sstream>

using namespace std;

#define ERROR_ID		0

#define PROCESS_ERROR(Condition)    \
{                                   \
		if (!(Condition))           \
		{                           \
			goto Exit0;             \
		}                           \
}

typedef unsigned char			BYTE;
typedef int						BOOL;
typedef unsigned long			DWORD;
typedef long long				LLONG;

int main(int argc, char* argv[])
{
	char		chWord;

	cin >> chWord;

	if (chWord == 'a' || chWord == 'e' || chWord == 'i' || chWord == 'o' || chWord == 'u')
	{
		cout << "vowel" << endl;
	}
	else
	{
		cout << "consonant" << endl;
	}
	return 0;
}