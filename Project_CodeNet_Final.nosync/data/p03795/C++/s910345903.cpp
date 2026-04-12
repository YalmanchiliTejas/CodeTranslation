#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int ret = N*800 - N/15*200;
	cout << ret << endl;

	return 0;
}
