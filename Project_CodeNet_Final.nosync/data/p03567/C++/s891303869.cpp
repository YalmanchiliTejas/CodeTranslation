#include <iostream>

using namespace std;

int main()
{
	char s[100];
	cin >> s;
	int ans = 0;

	for (int i = 0;i < 100;i++)
	{
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			ans++;
			break;
		}
	}
	if (ans > 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}