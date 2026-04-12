#include <iostream>

using namespace std;

int main()
{
	int P, Q, R; char C;

	while (true)
	{
		R = 0;

		for (int i = 0; i < 5; i++)
		{
			cin >> P >> Q;

			if (P == 0 && Q == 0) { return 0; }

			if (R < P + Q)
			{
				R = P + Q; C = i + 65;
			}
		}

		cout << C << ' ' << R << endl;
	}
}