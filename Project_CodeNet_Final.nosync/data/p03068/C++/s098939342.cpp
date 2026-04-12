#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
	int N, K;
	string S;
	cin >> N >> S >> K;

	char replace_char = S[K - 1];

	for (int i = 0; i < N; i++) {
		if (S[i] != replace_char) {
			S[i] = '*';
		}
	}
	cout << S;

	return 0;
}