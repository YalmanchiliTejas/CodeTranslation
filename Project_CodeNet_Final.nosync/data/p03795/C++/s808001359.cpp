#include <iostream>
using namespace std;
int main()
{
	long long x,y,n;
	cin >> n;
	x = n * 800;
	y = n / 15;
	cout << x - y * 200 << endl;
	return 0;
}