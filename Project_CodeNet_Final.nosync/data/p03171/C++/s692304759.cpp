#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll rec(int i, int j, vector<ll> &a_list, vector<vector<ll>> &memo) {
    if (memo.at(i).at(j) != -1) {
        return memo.at(i).at(j);
    }
    else if (i >= j) {
        memo.at(i).at(j) = 0;
        return 0;
    }
    else {
        int N = a_list.size();
        int turn = (i + N - j) % 2;
        ll score;
        if (turn == 0) {
            score = max(rec(i + 1, j, a_list, memo) + a_list.at(i),
                        rec(i, j - 1, a_list, memo) + a_list.at(j - 1));
        }
        else {
            score = min(rec(i + 1, j, a_list, memo),
                        rec(i, j - 1, a_list, memo));
        }
        memo.at(i).at(j) = score;
        return score;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> a_list(N);
    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        a_list.at(i) = tmp;
    }
    vector<vector<ll>> memo(N + 1, vector<ll>(N + 1, -1));
    ll max_score = rec(0, N, a_list, memo);
    ll sum_score = 0;
    for (int i = 0; i < a_list.size(); i++) {
        sum_score += a_list.at(i);
    }
    ll counterpart_score = sum_score - max_score;
    cout << max_score - counterpart_score << "\n";
    return 0;
}
