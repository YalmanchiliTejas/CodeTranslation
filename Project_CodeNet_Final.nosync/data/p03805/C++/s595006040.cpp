#include <cstdlib>
#include <climits>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <complex>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <unordered_set>
#include <unordered_map>

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/multi_array.hpp>

using namespace std;

#if 0
// memo
abs()

start_with(str, "hoge");
ends_with(str, "hoge");

std::sort(d.begin(), d.end());
d.erase(std::unique(d.begin(), d.end()), d.end());
#endif

using namespace boost;
using namespace boost::algorithm;


void dfs(const boost::multi_array<bool, 2>& mat,
         int u, int N, int& count,
         std::bitset<8>& not_visited)
{
    if (not_visited.none()) {
        ++count;
        return;
    }
    for (size_t v = 0; v < N; ++v) {
        if (mat[u][v]) {
            if (!not_visited[v]) {
                continue;
            }
            not_visited[v] = false;
            dfs(mat, v, N, count, not_visited);
            not_visited[v] = true;
        }
    }
}


int main()
{
    int N, M;

    std::cin >> N >> M;

    boost::multi_array<bool, 2> mat(boost::extents[N][N]);

    for (size_t i = 0; i < M; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;
        mat[a][b] = mat[b][a] = true;
    }

    int count = 0;
    std::bitset<8> not_visited;
    for (size_t i = 0; i < N; ++i) {
        not_visited[i] = true;
    }
    not_visited[0] = false;
    dfs(mat, 0, N, count, not_visited);

    std::cout << count << endl;

    return 0;
}
