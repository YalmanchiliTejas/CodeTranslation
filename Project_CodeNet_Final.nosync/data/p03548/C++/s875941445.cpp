#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;
#define print(x) cout<<(x)<<endl

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007



int main() {
	int X, Y, Z; cin >> X >> Y >> Z;

	int score = 0;

	X -= Z;

	while (X >= Y+Z) {
		X -= Y;
		score++;
		X -= Z;

	}
	print(score);



	



	return 0;
}