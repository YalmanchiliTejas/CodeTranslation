#include <bits/stdc++.h>

using namespace std;

int main() {

	string k;
	int d;
	cin >> k >> d;

	int numberOfDigits = k.length();
	// cout << numberOfDigits << endl;


	// The number of ways to make a number whose digit sum % d is x
	long long numberOfWays[d][numberOfDigits + 1];
	
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < numberOfDigits + 1; j++) {
			numberOfWays[i][j] = 0;
		}
	}

	numberOfWays[0][0] = 1;
	for (int i = 0; i < 10; i++) {
		numberOfWays[i % d][1]++;
	}

	int currentVal = 2;

	while (currentVal <= numberOfDigits) {

		for (int i = 0; i < d; i++) {

			for (int j = -9; j <= 0; j++) {

				int accessVal = i + j;
				while (accessVal < 0) {
					accessVal += d;
				}

				numberOfWays[i][currentVal] += numberOfWays[accessVal][currentVal - 1];

			}

			numberOfWays[i][currentVal] %= 1000000007;

		}

		currentVal++;

	}

	long long finalNumberOfWays = 0;
	long long currentSum = 0;

	while (!k.empty()) {

		int firstDigit = k[0] - '0';
		int numberOfDigits = k.length();
		
		if (k.length() == 1) {
			for (int i = 0; i <= firstDigit; i++) {
				if ((i + currentSum) % d == 0) {
					finalNumberOfWays += 1;
				}
			}
			break;
		}
		

		for (int i = 0; i < firstDigit; i++) {

			int accessVal = 0 - i - currentSum;
			while (accessVal < 0) {
				accessVal += d;
			}

			finalNumberOfWays += numberOfWays[accessVal][numberOfDigits - 1];
			finalNumberOfWays %= 1000000007;
			// cout << numberOfWays[accessVal][numberOfDigits - 1] << endl;
		}

		// k /= 10;
		k = k.substr(1);
		currentSum += firstDigit;

		// cout << "k: " << k << endl;
	}

	finalNumberOfWays--;
	cout << finalNumberOfWays % 1000000007 << endl;

	// numberOfWays[0]--;
	// for (int i = 0; i < d; i++) {
	// 	for (int j = 0; j < numberOfDigits + 1; j++) {
	// 		cout << numberOfWays[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

}