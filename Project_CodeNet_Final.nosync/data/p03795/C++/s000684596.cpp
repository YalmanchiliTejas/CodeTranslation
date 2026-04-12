#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;
	
	cout << n/15*600+(n-n/15)*800;
}