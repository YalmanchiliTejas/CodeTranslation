#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Precomputer the number of layers and patties at each level
auto getLayers(uint64_t N) {
    vector<pair<uint64_t,uint64_t>> output = {{1ull,1ull}};
    while (N > 0) {
        auto last = output.back();
        auto layers = 2*last.first + 3;
        auto patties = 2*last.second + 1;
        output.push_back(make_pair(layers, patties));
        N--;
    }
    return output;
}

// Consumes up to numLayers from a burger of given level
pair<uint64_t,uint64_t> consumeBurger(uint64_t level, uint64_t numLayers, const vector<pair<uint64_t,uint64_t>>& levelCounts) {
    if (numLayers >= levelCounts[level].first) {
        // All layers are edible
        return levelCounts[level];
    } else if (numLayers > 1 + levelCounts[level - 1].first) {
        // We can only eat somewhere inside the second sub-burger
        const auto preLayers = 1 + levelCounts[level - 1].first + 1;
        const auto prePatties = levelCounts[level - 1].second + 1;
        auto next = consumeBurger(level - 1, numLayers - preLayers, levelCounts);
        return make_pair(preLayers + next.first, prePatties + next.second);
    } else if (numLayers > 1) {
        // We can only eat somewhere inside the first sub-burger
        auto next = consumeBurger(level - 1, numLayers - 1, levelCounts);
        return make_pair(next.first + 1, next.second);
    } else {
        // There are no edible patties
        return make_pair(numLayers, 0ull);
    }
}    

auto solve(uint64_t N, uint64_t X) {
    const auto layers = getLayers(N);
    return consumeBurger(N, X, layers).second;
}

// Read parameters from standard input and call main solution function
int main() {
    uint64_t N, X;
    cin >> N >> X;
    cout << solve(N, X) << endl;
    return 0;
}