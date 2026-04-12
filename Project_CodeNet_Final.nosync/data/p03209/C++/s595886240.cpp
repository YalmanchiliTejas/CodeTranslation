
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define lint long long
#define INF 10000000000
lint N, X;
lint c[51];
lint dp(lint n, lint x) {

	if (n == 0) {
		return 1;
	}
	else {
		if (x == 1) {
			return 0;
		}
		else if (x <= 1 + c[n - 1]) {
			return dp(n - 1, x - 1);
		}
		else if(x == 2 + c[n-1]){
			return 1 + dp(n - 1, c[n - 1]);
		}
		else if (x <= 2 + 2 * c[n - 1]) {
			return 1 + dp(n - 1, c[n - 1]) + dp(n - 1, x - 2 - c[n - 1]);
		}
		else {
			return 1 + 2 * dp(n - 1, c[n - 1]);
		}

	}
}
int main() {
	//入力
	cin >> N >> X;
	//CはレベルNバーガーの全枚数
	c[0] = 1;
	for (int i = 0; i < N; i++)
	{
		c[i + 1] = 3 + 2 * c[i];

	}

	//レベルNバーガーの、下からX枚の範囲におけるパティの枚数
	cout << dp(N, X) << endl;
	return 0;

}