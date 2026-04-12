#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int n, x, y;
	cin >> n;
	x = n * 800;
	y = (n / 15) * 200;
	cout << x - y << endl;
	return 0;
}