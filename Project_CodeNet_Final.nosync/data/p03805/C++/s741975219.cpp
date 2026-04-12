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
#include <boost/dynamic_bitset.hpp>

constexpr int64_t DIV1097 = 1000000007LL;

using namespace std;


int main()
{
    int64_t N, M;
    std::cin >> N >> M;

    boost::multi_array<bool, 2> mat(boost::extents[N][N]);
    std::fill(mat.data(), mat.data() + mat.num_elements(), false);

    for (decltype(M) i = 0; i < M; ++i) {
        int64_t a, b;
        std::cin >> a >> b;
        a--;
        b--;
        mat[a][b] = mat[b][a] = true;
    }

    boost::dynamic_bitset<> visited(N);
    auto dfs = [&visited, N, &mat](auto DFS, int64_t n) -> int
        {
            if (visited.count() == visited.size()) {
                return 1;
            }

            int ret = 0;
            for (int64_t i = 0; i < N; ++i) {
                if (visited[i]) {
                    continue;
                }
                if (!mat[n][i]) {
                    continue;
                }
                // 状態追加
                visited[i] = true;
                ret += DFS(DFS, i);
                // 状態復帰
                visited[i] = false;
            }

            return ret;
        };

    visited[0] = true;
    int ret = dfs(dfs, 0);

    std::cout << ret << std::endl;

    return 0;
}
