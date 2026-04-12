#include <iostream>
using namespace std;

int main()
{
	int N;
	int n;
	int x = 800;
	int y = 200;
	cin >> N;
	n = N / 15;
	if (N >= 15)
		cout << (N*x) - (y*n);
	else
		cout << x*N;
	
}