#include <iostream>
#include <string>

using namespace std;

void solve()
{
	string S;
	cin >> S;
	for (int i = 0; i < S.size() - 1; ++i)
	{
		if (S[i] == 'A' && S[i + 1] == 'C')
		{
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

int main()
{
	solve();
	return(0);
}