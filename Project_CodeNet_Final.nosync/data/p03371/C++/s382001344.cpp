

#include<iostream>
#include<vector>
#include<algorithm>

struct pizza {
	std::size_t v, n;
	pizza(std::size_t v_, std::size_t n_) :v{ v_ }, n{n_} {}
};

int main() {
	std::size_t A, B, C, X, Y;
	std::cin >> A >> B >> C >> X >> Y;

	pizza a(A, X), b(B, Y);
	size_t total[5]{};
	std::fill(total, total+5, 100'000'000'000);

	total[0] = a.n * a.v + b.n *b.v;
	total[1] = 2 * C * std::max(b.n, a.n);

	total[2] = 2 * C*std::min(b.n, a.n);
	//total[2]+= (b.n < a.n) ? (a.n - b.n)*a.v : (b.n - a.n)*b.v;
	total[2] += (X < Y?(Y - X)*B :(X-Y) * A);
	/*for (auto&e : total) {
		//std::cout << e << "\n";
	}*/
	auto it = std::min_element(std::begin(total), std::end(total));
	std::cout << *it << "\n";
//	std::cin >> A;
	return 0;
}
