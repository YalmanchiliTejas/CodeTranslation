#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <list>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	long long n, x = 0, y = 0;
	cin >> n;
	x = n * 800;
	y = 200 * (n / 15);
	cout << x - y << endl;
}