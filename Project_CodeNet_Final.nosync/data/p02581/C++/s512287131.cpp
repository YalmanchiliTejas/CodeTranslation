#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VIII = vector<tuple<int, int, int>>;

int get_pair_card(int num_cards, int cards[])
{
    assert(num_cards == 3);
    if (cards[0] == cards[1] || cards[0] == cards[2])
        return cards[0];
    if (cards[1] == cards[2])
        return cards[1];
    return -1;
}

int get_alone_card(int num_cards, int cards[], int pair_card)
{
    for (int i = 0; i < num_cards; ++i) {
        if (cards[i] != pair_card) 
            return cards[i];
    }
    assert(false);
    return -1;
}

void update(const VIII &choice_vec, VVI &dp, VI &max_vec, int &max_score)
{
    for (auto tpl : choice_vec) {
        int p, q, val;
        tie(p, q, val) = tpl;
        if (dp[p][q] < val)
            dp[p][q] = val;
        if (dp[q][p] < val)
            dp[q][p] = val;
        if (max_vec.at(p) < val)
            max_vec.at(p) = val;
        if (max_vec.at(q) < val)
            max_vec.at(q) = val;
        if (max_score < val)
            max_score = val;
    }
}

int main()
{
    int N;
    cin >> N;
    VI A_vec(3 * N);
    for (int i = 0; i < 3 * N; ++i) {
        cin >> A_vec.at(i);
    }
    VVI dp(N + 1, VI(N + 1, -1));
    VI max_vec(N + 1, -1);
    dp[A_vec.at(0)][A_vec.at(1)] = 0;
    dp[A_vec.at(1)][A_vec.at(0)] = 0;
    max_vec.at(A_vec.at(0)) = 0;
    max_vec.at(A_vec.at(1)) = 0;
    int cards[3] = {};
    int offset_score = 0;
    int max_score = 0;
    for (int i = 0; i < N - 1; ++i) {
        VIII choice_vec;
        cards[0] = A_vec.at(3 * i + 2);
        cards[1] = A_vec.at(3 * i + 3);
        cards[2] = A_vec.at(3 * i + 4);
        if (cards[0] == cards[1] && cards[0] == cards[2]) {
            ++offset_score;
            continue;
        }
        int pair_card = get_pair_card(3, cards);
        if (pair_card > 0) {
            int p = pair_card;
            int q = get_alone_card(3, cards, pair_card);
            for (int j = 1; j <= N; ++j) {
                if (dp[p][j] == -1 && dp[j][p] == -1)
                    continue;
                dp[j][p] = dp[p][j] = max(dp[p][j], dp[j][p]);
                choice_vec.push_back({q, j, dp[j][p] + 1});
            }
        }
        for (int j = 0; j < 3; ++j) {
            int p = cards[j];
            if (dp[p][p] == -1)
                continue;
            int q = cards[(j + 1) % 3];
            int r = cards[(j + 2) % 3]; 
            choice_vec.push_back({q, r, dp[p][p] + 1});
        }
        for (int j = 0; j < 3; ++j) {
            int p = cards[j];
            int q = cards[(j + 1) % 3];
            choice_vec.push_back({p, q, max_score});
        }
        for (int j = 0; j < 3; ++j) {
            int p = cards[j];
            for (int k = 1; k <= N; ++k) {
                if (max_vec.at(k) == -1)
                    continue;
                choice_vec.push_back({p, k, max_vec.at(k)});
            }
        }
        update(choice_vec, dp, max_vec, max_score);
    }
    for (int j = 1; j <= N; ++j) {
        for (int k = 1; k <= N; ++k) {
            if (dp[j][k] == -1)
                continue;
            if (j == k && A_vec.at(3 * N - 1) == j)
                dp[j][k] = dp[j][k] + 1;
            if (max_score < dp[j][k])
                max_score = dp[j][k];
        }
    }
    max_score += offset_score;
    cout << max_score << endl;
}

