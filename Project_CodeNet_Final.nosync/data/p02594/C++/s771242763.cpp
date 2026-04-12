#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>

namespace adaptor = boost::adaptors;

void solve()
{
    int64_t X;
    std::cin >> X;
    std::string ans = X >= 30 ? "Yes" : "No";
    std::cout << ans << std::endl;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
