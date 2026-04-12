#include <iostream>
#include <math.h>
#include <string>
using namespace std;





int main()
{
	string S;
	int i;

	cin >> S;

	for (i = 0; i < 3; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C')	{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

    return 0;
}

