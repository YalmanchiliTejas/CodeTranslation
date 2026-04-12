#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
#include<climits>
using namespace std;

int main(void)
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int c2 = 2 * C;

	int cost;
	int ret = INT_MAX;
	for(int i=0; i<=max(X, Y); i++){
		cost = i * c2;
		cost += A * max(0, X-i);
		cost += B * max(0, Y-i);

		ret = min(ret, cost);
	}

	cout << ret << endl;

	return 0;
}
