#if !defined(__clang__) && defined(__GNUC__)
#include <bits/stdc++.h>
#else
#include <cstdlib>
#include <climits>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <complex>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#endif //  !defined(__clang__) && defined(__GNUG__)
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/math/common_factor_rt.hpp>

using namespace std;

int main()
{
    int64_t H, W;
    std::cin >> H >> W;

    boost::multi_array<char, 2> mat(boost::extents[H][W]);
// const auto Y = mat.shape()[0];
// const auto X = mat.shape()[1];

//std::fill(mat.data(), mat.data() + mat.num_elements(), almost_max<char>());

    for (auto p = mat.data(); p < (mat.origin() + mat.num_elements()); ++p) {
        std::cin >> *p;
    }

    std::vector<bool> hnoskip(H);
    std::vector<bool> wnoskip(W);
    
    for (int64_t h = 0; h < H; ++h) {
        for (int64_t w = 0; w < W; ++w) {
            if (mat[h][w] == '#') {
                hnoskip[h] = wnoskip[w] = true;
            }
        }
    }

    for (int64_t h = 0; h < H; ++h) {
        bool out = false;
        for (int64_t w = 0; w < W; ++w) {
            if (hnoskip[h] && wnoskip[w]) {
                out = true;
                std::cout << mat[h][w];
            }
        }
        if (out) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}
