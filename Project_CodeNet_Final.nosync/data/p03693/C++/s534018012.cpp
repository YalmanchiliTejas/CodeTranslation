#include<iostream>
using namespace std;
int main()
{
	int r, g, b;
	while (cin >> r >> g >> b)
	{
		int num = r * 100 + g * 10 + b;
		if (num % 4 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}