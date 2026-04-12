#include <iostream>

using namespace std;

int N;

int main(void)
{
	cin >> N;
	
	cout << 800*N - (N/15)*200 << endl;
	return 0;
}