#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
	string r, g, b;
	cin >> r >> g >> b;

	string n = r + g + b;
	string ret;
	if(stoi(n)%4 == 0)
		ret = "YES";
	else
		ret = "NO";

	cout << ret << endl;

	return 0;
}
