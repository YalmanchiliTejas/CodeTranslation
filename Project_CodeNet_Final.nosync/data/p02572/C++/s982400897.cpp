#include<iostream>
#include<vector>
#include<cinttypes>

using ull = std::uint64_t;
int main(){

	const ull prime_ = 1'000'000'000 + 7;

	std::uint32_t N;
	std::cin >> N;

	std::vector<ull> v( N, ull{} );
	
	ull sum_{};//<10^14
	for( auto& e : v )
	{
		std::cin >> e;
		sum_ += e;
	}
	//const auto sum_mod_ = sum_ % prime_;


	ull ans_{};
	for( const auto e : v )
	{
		//const auto sum_others_ =  sum_-e;
		sum_ -= e;
		ans_ += sum_%prime_ * e % prime_;
		ans_ %= prime_;
	}

//	ans_ %= prime_;
	std::cout << ans_ << "\n";

	return 0;
}