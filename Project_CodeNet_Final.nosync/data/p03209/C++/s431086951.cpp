#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Convenience function to read a vector of values from standard input
template <typename T>
auto readVector(T N) {
    vector<T> A;
    for (T i = 0; i < N; i++) {
        T Ai;
        cin >> Ai;
        A.push_back(Ai);
    }
    return A;
}

auto nextLevel(const string& input) {
    return "B" + input + "P" + input + "B";
}

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
    // If we can eat every layer in the burger at this level then can compute trivially, otherwise we have to recurse
    if (levelCounts[level].first <= numLayers) return levelCounts[level];
    // First outer bun
    auto consumedLayers = 1ull;
    auto consumedPatties = 0ull;
    if (consumedLayers == numLayers) return make_pair(consumedLayers, consumedPatties);
    // First inner burger
    auto next = consumeBurger(level - 1, numLayers - consumedLayers, levelCounts);
    consumedLayers += next.first;
    consumedPatties += next.second;
    if (consumedLayers == numLayers) return make_pair(consumedLayers, consumedPatties);
    // Middle patty
    consumedLayers++;
    consumedPatties++;
    if (consumedLayers == numLayers) return make_pair(consumedLayers, consumedPatties);
    // Second inner burger
    next = consumeBurger(level - 1, numLayers - consumedLayers, levelCounts);
    consumedLayers += next.first;
    consumedPatties += next.second;
    if (consumedLayers == numLayers) return make_pair(consumedLayers, consumedPatties);
    // Second outer bun
    consumedLayers++;
    return make_pair(consumedLayers, consumedPatties);
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