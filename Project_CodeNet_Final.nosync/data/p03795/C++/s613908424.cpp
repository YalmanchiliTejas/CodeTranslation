#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main()
{
	int32_t N;
	cin >> N;

	int32_t res = 0;
	for (int32_t i = 0; i < N; i++) {
		res += 800;
	}
	res -= (N / 15) * 200;
	cout << res << endl;

	return 0;
}
