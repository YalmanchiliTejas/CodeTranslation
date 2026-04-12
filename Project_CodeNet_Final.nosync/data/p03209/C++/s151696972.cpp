#include <bits/stdc++.h>

using namespace std;

int64_t burger_len[51];

int64_t calc_burger_len(int lv) {
    if (lv == 0) return burger_len[lv] = 1;
    int64_t prev_burger_len = calc_burger_len(lv - 1);
    return burger_len[lv] = 1 + prev_burger_len + 1 + prev_burger_len + 1;
}

map<pair<pair<int, int>, int>, int64_t> memo;

int64_t count_patti(int lv, int64_t start, int64_t end) { // count patti from [start, end) of level lv
    if (memo[make_pair(make_pair(lv, start), end)]) return memo[make_pair(make_pair(lv, start), end)];
    if (lv == 0) return memo[make_pair(make_pair(lv, start), end)] = 1;
    if (start == end) return memo[make_pair(make_pair(lv, start), end)] = 0;
    if (start == 0) return memo[make_pair(make_pair(lv, start), end)] = count_patti(lv, start + 1, end);
    if (start == burger_len[lv] / 2)
        return memo[make_pair(make_pair(lv, start), end)] = 1 + count_patti(lv, start + 1, end);
    if (end == burger_len[lv] / 2 + 1)
        return memo[make_pair(make_pair(lv, start), end)] = count_patti(lv, start, end - 1) + 1;
    if (end == burger_len[lv]) return memo[make_pair(make_pair(lv, start), end)] = count_patti(lv, start, end - 1);
    if (start < burger_len[lv] / 2 && end <= burger_len[lv] / 2)
        return memo[make_pair(make_pair(lv, start), end)] = count_patti(lv - 1, start - 1, end - 1);
    if (start > burger_len[lv] / 2 && end < burger_len[lv])
        return memo[make_pair(make_pair(lv, start), end)] = count_patti(lv - 1, start - burger_len[lv],
                                                                        end - burger_len[lv]);
    return memo[make_pair(make_pair(lv, start), end)] = count_patti(lv - 1, start - 1, burger_len[lv] / 2 - 1) + 1 +
                                                        count_patti(lv - 1, 0, end - burger_len[lv] / 2 - 1);
};

int main() {
    int N;
    int64_t X;
    cin >> N >> X;

    calc_burger_len(50);
    cout << count_patti(N, 0, X);
}