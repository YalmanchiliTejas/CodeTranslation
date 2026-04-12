#include <bits/stdc++.h>

int main() {
    using namespace std;
    string N;
    cin >> N;
    unsigned long K;
    cin >> K;
    const auto& score_1 = [](auto begin, auto end) -> unsigned long {
        string N{begin, end};
        if(N.size() < 1)return 0;
        return 9 * (N.size() - 1) + N[0] - 48;
    };
    const auto& score_2 = [&score_1](auto begin, auto end) -> unsigned long {
        string N{begin, end};
        if(N.size() < 2)return 0;
        return 81 * (N.size() - 1) * (N.size() - 2) / 2 + (N[0] - 49) * 9 * (N.size() - 1) + score_1(find_if_not(N.begin() + 1, N.end(), [](auto t){return t == '0';}), N.end());
    };
    const auto& score_3 = [&score_2](auto begin, auto end) -> unsigned long {
        string N{begin, end};
        if(N.size() < 3)return 0;
        return 729 * (N.size() - 1) * (N.size() - 2) * (N.size() - 3) / 6 + (N[0] - 49) * 81 * (N.size() - 1) * (N.size() - 2) / 2 + score_2(find_if_not(N.begin() + 1, N.end(), [](auto t){return t == '0';}), N.end());
    };
    if(K == 1) cout << score_1(N.begin(), N.end()) << endl;
    else if(K == 2) cout << score_2(N.begin(), N.end()) << endl;
    else cout << score_3(N.begin(), N.end()) << endl;
    return 0;
}