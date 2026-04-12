#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	int ans = 0;
	cin >> S;

	int ss = S.size() -1;
	for (int s = 0; s < ss; s++) {
		if (S[s] == 'A' && S[s+1] == 'C')
			ans = 1;
	}

	if (ans)cout << "Yes";
	else cout << "No";

	return 0;
}