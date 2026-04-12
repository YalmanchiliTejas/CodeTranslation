#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <type_traits>
#include <limits>
#include <random>

using namespace std;

using ll = long long;

#define rep(i,N) for(long long i = 0;i < (long long)N; ++i)

int N;
int n[100];

int main() {
	cin >> N;
	if (N == 3 || N == 5 || N == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}


	return 0;
}
