#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
#include <math.h>

using namespace std;

int main()
{
	int N, K;
	string S, key, w;
	cin >> N >> S >> K;
	key = S[K - 1];
	for (int val = 0; val < N; val++) {
		w = S[val];
		if (w != key) {
			S[val] = '*';
		}
	}
	cout << S << endl;
}