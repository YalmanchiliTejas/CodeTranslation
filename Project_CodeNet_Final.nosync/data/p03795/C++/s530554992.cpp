#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;

	cout << n * 800 - (n / 15) * 200 << endl;

	return 0;
}
