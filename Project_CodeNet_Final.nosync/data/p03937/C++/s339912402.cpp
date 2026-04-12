#include <iostream>
#include <string>

using namespace std;

int main()
{
	int H, W;
	int count = 0;

	cin >> H >> W;

	string A;
	for (int i = 0; i < H; i++)
	{
		cin >> A;

		for (int j = 0; j < W; j++)
		{
			if (A[j] == '#')
				count++;
		}
	}

	if (count == H + W - 1)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;

	return 0;
}
