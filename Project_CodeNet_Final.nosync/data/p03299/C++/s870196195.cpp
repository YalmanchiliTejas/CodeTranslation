#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include <cassert>
using namespace std;

const int MOD = 1e9 + 7;

inline void ModSum(int& x, int y)
{
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    if (x < 0) {
        x += MOD;
    }
}

inline int GetModSum(int x, int y)
{
    ModSum(x, y);
    return x;
}

inline void ModMul(int& x, int y)
{
    x = (1LL * x * y) % MOD;
}

inline int GetModMul(int x, int y)
{
    ModMul(x, y);
    return x;
}

inline int GetBinaryPow(int x, int pw)
{
    int r = 1;
    while (pw > 0) {
        if (pw & 1) {
            ModMul(r, x);
        }
        ModMul(x, x);
        pw >>= 1;
    }
    return r;
}

struct TSolver
{
    int N;
    vector<int> Heights;

    unordered_map<int, int> HeightToIndex;
    vector<int> IndexToHeight;

    void Setup()
    {
    }

    bool Read()
    {
        if (!(cin >> N)) {
            return false;
        }
        Heights.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> Heights[i];
        }
        return true;
    }

    void CompressHeights()
    {
        HeightToIndex.clear();
        IndexToHeight.clear();

        auto add = [this] (int height) {
            if (HeightToIndex.find(height) != HeightToIndex.end()) {
                return;
            }
            auto index = IndexToHeight.size();
            IndexToHeight.push_back(height);
            HeightToIndex[height] = index;
        };

        add(0);
        for (int i = 0; i < N; ++i) {
            add(Heights[i]);
        }
    }

    void Solve()
    {
        CompressHeights();

        const auto zeroHeightIndex = HeightToIndex.at(0);
        const int heightCount = HeightToIndex.size();

        vector<vector<int>> dp(N, vector<int>(heightCount));
        dp[0][zeroHeightIndex] = 1;

        for (int i = 0; i + 1 < N; ++i) {
            for (int j = 0; j < heightCount; ++j) {
                auto middleHeight = IndexToHeight[j];

                if (middleHeight > Heights[i]) {
                    assert(dp[i][j] == 0);
                    continue;
                }

                if (j == zeroHeightIndex) {
                    auto mul = GetBinaryPow(2, max(0, Heights[i] - Heights[i + 1]));
                    ModSum(dp[i + 1][j], GetModMul(dp[i][j], mul));
                    ModSum(dp[i + 1][HeightToIndex.at(min(Heights[i], Heights[i + 1]))], GetModMul(GetModMul(dp[i][j], mul), 2));
                } else {
                    assert(middleHeight > 0);
                    if (Heights[i + 1] <= middleHeight) {
                        ModSum(dp[i + 1][HeightToIndex.at(Heights[i + 1])], GetModMul(GetModMul(dp[i][j], GetBinaryPow(2, Heights[i] - middleHeight)), 2));
                    } else if (Heights[i + 1] > middleHeight && Heights[i + 1] <= Heights[i]) {
                        auto mul = GetBinaryPow(2, Heights[i] - Heights[i + 1]);
                        ModSum(dp[i + 1][HeightToIndex.at(Heights[i + 1])], GetModMul(dp[i][j], mul));
                        ModSum(dp[i + 1][j], GetModMul(dp[i][j], mul));
                    } else {
                        ModSum(dp[i + 1][HeightToIndex.at(Heights[i])], dp[i][j]);
                        ModSum(dp[i + 1][j], dp[i][j]);
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < heightCount; ++i) {
            auto diff = Heights[N - 1] - IndexToHeight[i];
            if (diff < 0) {
                assert(dp[N - 1][i] == 0);
                continue;
            }
            ModSum(result, GetModMul(dp[N - 1][i], GetBinaryPow(2, diff)));
        }

        cout << result << '\n';
    }

    void TearDown()
    {
        cout.flush();
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    TSolver solver;
    solver.Setup();
    while (solver.Read()) {
        solver.Solve();
        solver.TearDown();
    }

    return 0;
}
