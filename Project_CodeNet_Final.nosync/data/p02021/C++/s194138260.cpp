#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#include <map>
using namespace std;

int N, A[100009], sum = 0, minx = (1 << 30);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i]; sum += A[i];
		minx = min(minx, sum / i);
	}
	cout << minx << endl;
	return 0;
}
