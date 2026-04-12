#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<tuple>
#include<queue>
#define LL long long
#define TT std::tuple<LL,LL,LL>
#define PP std::pair<LL,LL>
LL A, B, C, X, Y;
LL ans;
int main() {
	std::cin >> A >> B >> C >> X >> Y;
	if (X < Y) {
		std::swap(X, Y);
		std::swap(A, B);
	}
	if (A + B > C * 2) {
		ans += Y*C*2;
		X -= Y;
		Y = 0;
	}
	if (A > C * 2) {
		ans += X * C * 2;
		X = 0;
	}
	ans += X * A;
	ans += Y * B;
	std::cout << ans << std::endl;
	return 0;
}