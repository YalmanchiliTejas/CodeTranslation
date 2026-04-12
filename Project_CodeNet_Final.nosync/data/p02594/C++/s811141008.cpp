#include <iostream>
using namespace std;

int main()
{
	auto& in = cin;

	int X;
	in >> X;
	if (X >= 30)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
