#include <bits/stdc++.h>

int main() {
	int A, B, C, X, Y;
	std::cin >> A >> B >> C >> X >> Y;

	int N_A = 0, N_B = 0, N_AB = 0, ans;
	if(A + B <= 2 * C) {
		ans = X * A + Y * B;
	} else {
		N_AB = std::min(X, Y);
		N_A = X - N_AB;
		N_B = Y - N_AB;

		ans = std::min(2 * std::max(X, Y) * C, N_A * A + N_B * B + 2 * N_AB * C);
	}

	std::cout << ans << std::endl;
 }
