#include <bits/stdc++.h>
using namespace std;

int main() {
	string	S;
	cin >> S;
	int a;
	int b;
	a = 0;
	b = 0;
	for (int i = 0; i < 3; i++)
	{
		if (S.at(i) == 'A')	
			a++;
		if (S.at(i) == 'B')
			b++;
	}
	if (a > 0 && b > 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
