#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include <string>
#include <utility>
#include<array>
#include<set>
#define EPS (1e-7)
using namespace std;




int main() {

	int A, B, C, X, Y, cost;
	int mincost = 6000000000;
	cin >> A >> B >> C >> X >> Y;

	for (auto i = 0; i <= max(X,Y); i++)
	{
		
		mincost = min(mincost, 2 * C*i + A * max((X - i), 0) + B * max((Y - i), 0));
	}

	cout << mincost << endl;

	return 0;
}