#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <climits>
#include <vector>
using namespace std;

#define ll long long int

const int MOD = 1000000007;

int main() {

	int N, pay, get;

	cin >> N;

	pay = 800 * N;
	get = ((N - (N % 15)) / 15) * 200;

	cout << pay - get << endl;

	return 0;
}