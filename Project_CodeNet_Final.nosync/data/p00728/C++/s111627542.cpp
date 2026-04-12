#include <iostream>
using namespace std;

int N, S;
int main() {
	while(cin >> N && N > 0) {
		int sum = 0;
		int largest = 0;
		int smallest = 1000;

		for(int i = 0; i < N; i++) {
			cin >> S;
			sum += S;
			if(S > largest) largest = S;
			if(S < smallest) smallest = S;
		}

		sum = sum - largest - smallest;
		//cout << "laegest:" << largest << endl;
		//cout << "smallest:" << smallest << endl;
		cout << sum / (N-2) << endl;

	}
}