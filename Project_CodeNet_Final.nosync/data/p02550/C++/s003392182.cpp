#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, X, M;
    cin >> N >> X >> M;

    vector<int64_t> appear(M + 1, -1);
    vector<int64_t> A;
    int64_t curr_value = X;
    for (int64_t i = 0; ; i++) {
        A.push_back(curr_value);
        if (appear[curr_value] != -1) {
            break;
        }
        appear[curr_value] = i;
        curr_value = curr_value * curr_value % M;
    }

    int64_t loop_start_index = appear[A.back()];
    int64_t loop_end_index = A.size() - 1;
    int64_t loop_period = loop_end_index - loop_start_index;
    int64_t loop_num = (N - loop_start_index) / loop_period;
    int64_t ans = 0;

    //ループまで
    for (int64_t i = 0; i < loop_start_index; i++) {
        (ans += A[i]);
    }

    //ループ中
    int64_t loop_sum = 0;
    for (int64_t i = loop_start_index; i < loop_end_index; i++) {
        loop_sum += A[i];
    }
    ans += loop_sum * loop_num;

    //ループ後
    int64_t index = loop_start_index + loop_period * loop_num;
    for (int64_t i = index; i < N; i++) {
        (ans += A[loop_start_index + i - index]);
    }

    cout << ans << endl;
}