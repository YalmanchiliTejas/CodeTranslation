#include <bits/stdc++.h>

#define right_index(left_index, seq_length) (left_index + seq_length - 1)

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<long long int>> X_minus_Y(N + 1, vector<long long int>(N));
    for (int index = 0; index < N; index++) cin >> X_minus_Y[1][index];


    for (int seq_length = 2; seq_length <= N; seq_length++)
        for (int left_index = 0; right_index(left_index, seq_length) < N; left_index++)
            X_minus_Y[seq_length][left_index] = max(X_minus_Y[1][right_index(left_index, seq_length)] - X_minus_Y[seq_length - 1][left_index],
                                                    X_minus_Y[1][left_index] - X_minus_Y[seq_length - 1][left_index + 1]);

	cout << X_minus_Y[N][0];

    return 0;
}