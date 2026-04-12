
#include<algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<cmath>

using ull = unsigned long long;
using ui = unsigned int;
ull tab[100500]{};
int main() {

	ui n{};
	std::cin >> n;
	std::vector<ull> v;
	v.resize(n);

	for (ui i{}; i < n; ++i)
		std::cin >> v[i];

	std::sort(std::begin(v), std::end(v));

//	std::cout << "\n";
	for (ui i{ 0 }; i < n / 2 + n % 2 == 0 ? 0 : 1; ++i) {
		//std::cout << "i " << n-i-1 << "\n";
		auto ti = 2 * i + (i % 2 == 0 ? 1 : 0);
		//		std::cout <<"i, ti "<<i<<", "<< ti << "\n";
		tab[ti] = v[n - i - 1];
	}

	//	std::cout << "\n";
	for (ui i{ 0 }; i < n / 2; ++i) {
		auto ti = 2 * i + (i % 2 == 0 ? 0 : 1);
		//		std::cout << "i, ti " << i << ", " << ti << "\n";
		tab[ti] = v[i];
	}



	auto lit = std::find(std::begin(tab), std::end(tab), 0);
	auto it = lit + 1;
	if (it != std::end(tab) && *it != 0)
		std::iter_swap(lit, it);


//	std::cout << "t " << tab[1] << " " << tab[0] << "\n";
	ull result = tab[1] - tab[0];
	ull d{};
	for (ui i{ 2 }; i < n; ++i) {

		if (tab[i] != 0 && tab[i - 2] != 0)
			d = (i - 1) % 4 < 2 ?
			tab[i] - tab[i - 2]
			: tab[i - 2] - tab[i];

		result += d;
//		std::cout << d << "\n";
	}

	auto mid = v[n / 2];
	
	auto r3 = n % 4 == 3;
	auto r1 = n % 4 == 1;

	auto ld = mid - v[n / 2 - 1];
	auto rd = v[n / 2 + 1] - mid;

	//auto ld_gt_rd = ld < rd;
//	std::cout << "l,r " << ld << " " << rd<<"\n";
	if (
 		   (r3 && ld < rd) || (r1 && ld > rd)
		) {
		auto d =  std::max(ld,rd) - std::min(ld,rd);
		result += d;
//		std::cout << "d " << d << "\n";
	}

	std::cout << result << "\n";
	//for (auto&e : tab)
	//	if (e != 0)
	//		std::cout << e << " ";


	return 0;
}