#include <string>
#include <iostream>

using namespace std;

int main()
{
	int A[6], N, S, T;

	string com;

	while (true)
	{
		cin >> N;

		if (N == 0) { break; }

		A[0] = 1;
		A[1] = 2;
		A[2] = 3;
		A[3] = 5;
		A[4] = 4;
		A[5] = 6;

		S = 1;

		for (int i = 0; i < N; i++)
		{
			cin >> com;

			if (com == "North")
			{
				T = A[0];

				A[0] = A[1];
				A[1] = A[5];
				A[5] = A[3];
				A[3] = T;
			}

			if (com == "East")
			{
				T = A[0];

				A[0] = A[4];
				A[4] = A[5];
				A[5] = A[2];
				A[2] = T;
			}

			if (com == "West")
			{
				T = A[0];

				A[0] = A[2];
				A[2] = A[5];
				A[5] = A[4];
				A[4] = T;
			}

			if (com == "South")
			{
				T = A[0];

				A[0] = A[3];
				A[3] = A[5];
				A[5] = A[1];
				A[1] = T;
			}

			if (com == "Right")
			{
				T = A[1];

				A[1] = A[2];
				A[2] = A[3];
				A[3] = A[4];
				A[4] = T;
			}

			if (com == "Left")
			{
				T = A[1];

				A[1] = A[4];
				A[4] = A[3];
				A[3] = A[2];
				A[2] = T;
			}

			S += A[0];
		}

		cout << S << endl;
	}

	return 0;
}