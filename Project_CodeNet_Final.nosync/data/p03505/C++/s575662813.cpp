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
#include <array>
#include <bitset>
#include <cstdlib>

using int64 = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int64 K, A, B;
    std::cin >> K >> A >> B;
    
    if (A >= K) {
        std::cout << 1 << std::endl;
        return 0;
    }

    if (A <= B) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::cout << 2 * (((K - A) + (A - B) - 1) / (A - B)) + 1 << std::endl;

    return 0;
}
