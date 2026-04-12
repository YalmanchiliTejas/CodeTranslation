// #include "deque.h"
#include <iostream>
#include <vector>

long long score_difference(const std::vector<int>& sequence)
{
    std::vector<std::vector<long long>> dp(
        sequence.size(), std::vector<long long>(sequence.size()));

    bool first_player_turn{true};
    for (int left = sequence.size() - 1; left >= 0; --left) {
        for (int right = left; right < sequence.size(); ++right) {
            if (left == right)
                dp[left][right] = sequence[left];
            else
                dp[left][right] =
                    std::max(sequence[left] - dp[left + 1][right],
                             sequence[right] - dp[left][right - 1]);
        }
    }

    return dp.front().back();
}

int main(int argc, char* argv[])
{
    size_t seq_size;
    std::cin >> seq_size;
    std::vector<int> sequence(seq_size);
    for (size_t i = 0; i < seq_size; ++i) {
        int number;
        std::cin >> number;
        sequence[i] = number;
    }
    std::cout << score_difference(sequence) << std::endl;
    return 0;
}
