#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	int out = 800 * N;
	int in = 200 * (N / 15);
	cout << out - in << endl;

	return 0;
}