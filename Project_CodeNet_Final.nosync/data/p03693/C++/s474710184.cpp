#include<bits/stdc++.h>
using namespace std;

int main()
{
	int temp;
	int number = 0;
	for (int i = 0; i < 3; ++i)
	{
		cin >> temp;
		number *= 10;
		number += temp;
	}

	if (number % 4 == 0) cout << "YES";
	else cout << "NO";


	return 0;
}