
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int main() {

	int w{}, h{};
	std::cin >> h >> w;
	std::vector<std::string> v;

	const auto white = '.';

	for (int i{}; i < h; i++) {
		std::string s;
		std::cin >> s;
		auto all_white = std::all_of(std::begin(s), std::end(s)
			, [&](const auto& x) {return white == x; });

		if (!all_white)
			v.emplace_back(std::move(s));
	}

	std::vector<int>wv;
	wv.reserve(w);

	for (int i{}; i < w; i++) {

		bool all_white = true;
		for (auto&e : v) {
			const auto&cs = e;
			all_white &= cs[i] == white;
		}

		if (all_white) {
			for (auto&s : v) 
				for (int wi{ i}; wi+1 < w;wi++)
					s[i] = s[i+1];
			
		} else{
			wv.push_back(i);

		}

	}

	for (const auto& e : v) {
	
		for(auto &we:wv){
			std::cout << e[we];
		}

		std::cout << "\n";
	}
	return 0;
}