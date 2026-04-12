#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int r,g,b;
	cin >> r >> g >> b;
	int c,d;
	c = r * 100 + g*10 + b;
	d = c % 4;
	if (d == 0)
	{
		cout << "YES" << endl;
		/* code */
	}
	else cout << "NO" << endl;
	return 0;
}