#include "bits/stdc++.h"
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/dynamic_bitset.hpp>
namespace adaptor = boost::adaptors;
using index_t = std::size_t;

namespace lib
{
	using graph_t = std::vector<std::set<index_t>>;
	template<class T>using weighted_graph_t = std::vector<std::map<index_t, T>>;
	template<class T>using pair = std::pair<T, T>;

	struct max_t
	{
		template<class T>constexpr T operator()(T const& lhs, T const& rhs)const
		{
			return std::max(lhs, rhs);
		}
	};
	struct min_t
	{
		template<class T>constexpr T operator()(T const& lhs, T const& rhs)const
		{
			return std::min(lhs, rhs);
		}
	};

	constexpr max_t max;
	constexpr min_t min;

	template<class T>auto order_by(T func)
	{
		return [=](auto&& lhs, auto&& rhs)
		{
			return func(lhs) < func(rhs);
		};
	}

	template<class T>constexpr auto max_v = std::numeric_limits<T>::max();
	template<class T>constexpr auto min_v = std::numeric_limits<T>::min();

	template<class T>using p_queue = std::priority_queue<T, std::vector<T>, std::greater<>>;
	
	template<class T>constexpr T pow(T val, std::uint64_t p)
	{
		auto ret = T(1);
		auto s = 1ULL;
		for (auto i = 0; i < 63; ++i, s <<= 1)
		{
			if (p & s)
			{
				ret *= val;
			}
			val *= val;
		}
		return ret;
	}
	template<class Range>void sort(Range& rng)
	{
		std::sort(std::begin(rng), std::end(rng));
	}
	template<class Range, class Pred>void sort(Range& rng, Pred pred)
	{
		std::sort(std::begin(rng), std::end(rng), pred);
	}
}

namespace lib
{
	template<std::uint64_t Mod>class modnum
	{
		std::uint64_t val;
		void clamp()
		{
			val %= Mod;
		}
	public:
		modnum() = default;
		modnum(std::int64_t v) :val()
		{
			if (v < 0)
			{
				v += (std::abs(v) / Mod + 1) * Mod;
			}
			val = v;
			clamp();
		}
		modnum(std::uint64_t v) :val(v)
		{
			clamp();
		}
		modnum(std::int32_t v) :modnum(static_cast<std::int64_t>(v))
		{

		}
		modnum(std::uint32_t v) :modnum(static_cast<std::uint64_t>(v))
		{

		}
		friend std::ostream& operator<<(std::ostream& os, modnum const& num)
		{
			return os << num.val;
		}
		auto& operator+=(modnum const& rhs)
		{
			val += rhs.val;
			clamp();
			return *this;
		}
		auto& operator-=(modnum const& rhs)
		{
			val += Mod - rhs.val;
			clamp();
			return *this;
		}
		auto& operator*=(modnum const& rhs)
		{
			val *= rhs.val;
			clamp();
			return *this;
		}
		auto& operator/=(modnum const& rhs)
		{
			val *= pow(rhs, Mod - 2).val;
			clamp();
			return *this;
		}
		friend auto operator+(modnum const& lhs, modnum const& rhs)
		{
			auto ret = lhs;
			ret += rhs;
			return ret;
		}
		friend auto operator-(modnum const& lhs, modnum const& rhs)
		{
			auto ret = lhs;
			ret -= rhs;
			return ret;
		}
		friend auto operator*(modnum const& lhs, modnum const& rhs)
		{
			auto ret = lhs;
			ret *= rhs;
			return ret;
		}
		friend auto operator/(modnum const& lhs, modnum const& rhs)
		{
			auto ret = lhs;
			ret /= rhs;
			return ret;
		}

		auto const& operator*()const
		{
			return val;
		}
	};
}
using mod_t = lib::modnum<1000000007>;

void Main()
{
	std::size_t N;
	std::cin >> N;
	mod_t sum = 0, dsum = 0;
	for (auto i : boost::irange(N))
	{
		std::int64_t v;
		std::cin >> v;
		sum += v;
		dsum += lib::pow<mod_t>(v, 2);
	}
	sum *= sum;
	std::cout << (sum - dsum) / 2 << std::endl;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}