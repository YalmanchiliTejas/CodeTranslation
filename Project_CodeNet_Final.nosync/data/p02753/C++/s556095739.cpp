#include <iostream>
#include <string>
using namespace std;


int main()
{
	string stations;
	cin >> stations;
	if (stations[0] != stations[1] || stations[0] != stations[2])
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}