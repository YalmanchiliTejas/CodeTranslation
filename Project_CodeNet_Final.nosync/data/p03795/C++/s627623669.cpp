#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;

	int m = N / 15;

	int x = 800 * N;
	int y = 200 * m;

	cout << x - y;
	return 0;
}