/*input
60
*/

#include <iostream>

using namespace std;

int main()
{

	int N;
	cin >> N;

	int total = 0;
	total += N * 800;
	total -= (N / 15) * 200;

	cout << total << endl;

	return 0;
}
