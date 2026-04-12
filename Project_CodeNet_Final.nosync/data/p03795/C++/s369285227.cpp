#include <iostream>

using namespace std;

void solve()
{
	int N;
	cin >> N;
	cout << 800 * N - 200 * (N / 15) << endl;
}

int main()
{
	solve();
	return(0);
}