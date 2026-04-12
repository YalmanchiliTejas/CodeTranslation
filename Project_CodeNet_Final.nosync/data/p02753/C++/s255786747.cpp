#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main(int argc, char const* argv[])
{
	char S[100];
	cin >> S;
	if(strlen(S) == 3)
	{
		if((S[0] == S[1] && S[1] == S[2]))
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}

	return 0;
}
