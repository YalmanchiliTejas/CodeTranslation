#include <bits/stdc++.h>
using namespace std;

#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
namespace adaptor = boost::adaptors;

// 多倍長テンプレ
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

using ll = long long;
using ull = unsigned long long;

/*
	int N;
	std::cin >> N;
	std::vector<int> vec(N);
	for (auto& v : vec)
	{
		std::cin >> v;
	}
*/

void Main()
{
	int A;
	cin >> A;

	if (A >= 30) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return;
}

int main()
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	Main();
}