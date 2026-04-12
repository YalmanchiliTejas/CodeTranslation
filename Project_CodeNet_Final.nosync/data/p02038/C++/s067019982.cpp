
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

int M[2][2] = { {1,1},{0,1} };

int main(void)
{
	int N;
	cin >> N;
	char B;
	cin >> B;
	int A = (B == 'T');
	for (int i = 1; i < N; ++i) {
		char p; cin >> p;
		int q = (p == 'T');
		A = M[A][q];
	}
	cout << (A ? 'T' : 'F') << endl;
	return 0;
}

