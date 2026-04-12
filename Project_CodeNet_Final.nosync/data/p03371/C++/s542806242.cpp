#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <utility>
using ll = long long int;
using namespace std;
double pi = 3.141592653589793238;

#define FOR(i,N) for(int i=0;i<N;i++)
#define pb(x) push_back(x)

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	cout << min({ max(X, Y) * 2 * C ,2 * C * X + B * max(Y - X, 0),2 * C * Y + A * max(X - Y, 0),X * A + Y * B });
	
}