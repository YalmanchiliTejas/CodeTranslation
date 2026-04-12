#include <iostream>

using namespace std;

void print(int a, int b);

int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a;
	cin >> b;

	print(a, b);
	
	return 0;
}

void print(int a, int b)
{
	if(a < b)
	{
		cout << "a < b" << endl;
	}
	else if(a > b)
	{
		cout << "a > b" << endl;
	}
	else
	{
		cout << "a == b" << endl;
	}
}