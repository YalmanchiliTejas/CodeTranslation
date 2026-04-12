#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<numeric>
#include<algorithm>
using namespace std;

int main() {
	int N;
	int M;
	cin >> N;
	cin >> M;

	if (N == M) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}