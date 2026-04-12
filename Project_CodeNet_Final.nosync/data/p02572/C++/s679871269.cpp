#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

#include <math.h>
#include <iomanip>
#include <vector>
#include <queue>
#include <climits>
using Graph = vector<vector<int>>;
const double PI = 3.14159265358979323846;
#define int long long


signed main() {

	const int SIZE = 200020;
	const int IX = 1000000007;

	int N;
	int A[SIZE];

	cin >> N;
	
	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		sum -= A[i];
		ans = (ans + (sum%IX)*(A[i]%IX)) % IX;
	}




	cout << ans << endl;

	cin >> ans;

	return 0;


}

