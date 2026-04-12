#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <limits.h>
#include <set>
#include <map>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,N) for (int i=0;i<N;i++)

//変数
ll A, B, C, X, Y;

//解法
void solve() {

	C *= 2;

	ll ans1 = max(X, Y)*C;
	ll ans2 = X*A + Y*B;

	ll ans3=min(X,Y)*C;
	if (X > Y) {
		ans3 += (X - Y)*A;
	}
	else {
		ans3 += (Y - X)*B;
	}

	cout << min(min(ans1, ans2), ans3);

	return;
}

int main() {
	//入力
	cin >> A >> B >> C >> X >> Y;
	solve();
	cout << endl;
	return 0;
}
