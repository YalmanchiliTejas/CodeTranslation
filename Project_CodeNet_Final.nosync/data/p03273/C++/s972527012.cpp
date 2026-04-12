#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <assert.h>
#include <utility>
#include <tuple>

using int64 = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> a;
    for (int i = 0; i < H; i++) {
        std::string row;
        std::cin >> row;

        bool all = true;
        for (int j = 0; j < W; j++) {
            all = all && (row[j] == '.');
        }
        if (!all) a.push_back(row);
    }

    for (auto row : a) {
        for (int j = 0; j < W; j++) {
            bool all = true;
            for (auto row2 : a) {
                all = all && (row2[j] == '.');
            }
            if (!all) std::cout << row[j];
        }
        std::cout << std::endl;
    }

    return 0;
}
