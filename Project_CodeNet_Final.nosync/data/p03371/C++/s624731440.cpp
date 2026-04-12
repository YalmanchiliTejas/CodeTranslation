#include<iostream>
#include<algorithm>

int main() {

	int A, B, C, X, Y, cost, m, left;

	std::cin >> A >> B >> C >> X >> Y;

	if (2 * C >= A + B) {
		cost = A * X + B * Y;
	}
	else {
		m = std::min(X, Y);
		cost = 2 * C * m;
		X = X - m;
		Y = Y - m;
		left = std::max(X, Y);
		cost += std::min( 2 * C*left, std::max(A*X, B*Y));
	}

	std::cout << cost << std::endl;

	return 0;
}