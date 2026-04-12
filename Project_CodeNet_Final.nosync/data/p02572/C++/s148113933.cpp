#include <iostream>
#include <vector>

#define M 1000000007

using namespace std;


int main() {
	int n;
	vector<long long> a;
	long long fact = 0;
	long long sum = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int next;
		cin >> next;

		a.push_back(next);
		fact = (fact + next) % M;
	}

	for (int i = 0; i < n; i++) {
		fact = (fact - a[i] + M) % M;
		sum = (sum + (a[i] * fact) % M) % M;
	}

	cout << sum % M << endl;
}
