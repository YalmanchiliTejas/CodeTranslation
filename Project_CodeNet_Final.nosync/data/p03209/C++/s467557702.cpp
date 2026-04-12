#include <iostream>

using namespace std;

using ull = long long int;

ull Patty[101] = {};
ull Burger[101] = {};

int main() {

	ull N, X, answer = 0;
	cin >> N >> X;

	Patty[0] = 1;
	Burger[0] = 1;

	for (int i = 0; i < 100; i++)
	{
		Burger[i + 1] = 2 * Burger[i] + 3;
	}

	for (int i = 0; i < 100; i++)
	{
		Patty[i + 1] = 2 * Patty[i] + 1;
	}

	for (int i = N;X > 0 && i >= 0; i--) 
	{
		if (X >= Burger[i]) {
			X -= Burger[i];
			answer += Patty[i];

			i++;

			if (X != 0) {
				X--;
				answer++;
			}
		}
		else {
			X--;
		}
	}

	cout << answer << endl;

	return 0;
}