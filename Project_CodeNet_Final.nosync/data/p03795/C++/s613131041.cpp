#include <iostream>

using namespace std;

main()
{
	int N;
	int x;
	int y;
	int difference;

	cin >> N;

	x = 800 * N;
	y = 200*(N / 15);

	difference = x - y;

	cout << difference << endl;

	return 0;

}