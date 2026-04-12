#include <algorithm>
#include <iostream>
using namespace std;
int N, S;
int main() {
	while (cin >> N && N>0) {
		int sum = 0;
		int largest = 0;
		int smallest = 1001;
		for (int i=0; i<N; ++i) {
			cin >> S;
			largest = max(largest,S);
			smallest = min (smallest,S);
			sum += S;
		}
		sum = sum - largest;
		sum = sum - smallest;
		cout << sum /(N-2) << endl;
	}
	return 0;
}