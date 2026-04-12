#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<math.h>
#include<unordered_set>

using namespace std;

int main() {
	int A, B, C, X, Y;
	long long ans = 0;

	cin >> A >> B >> C >> X >> Y;

	if (A + B > C * 2) {
		int Z = min(X, Y);
		X -= Z;
		Y -= Z;
		ans += Z * C * 2;
	}

	if (A > C * 2)ans += X * C * 2;
	else ans += X * A;

	if (B > C * 2)ans += Y * C * 2;
	else ans += Y * B;

	cout << ans << endl;

	
	return 0;
}