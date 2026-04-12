#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    long long ans_center_min = 0, ans_center_max = 0;
    int left, right, left_p, right_p;

    left = A.front(), right = A.front(), left_p = 1, right_p = N - 1;
    while (true) {
        ans_center_min += abs(right - A[right_p]);
        right = A[right_p--];
        if (left_p > right_p) break;

        ans_center_min += abs(left - A[right_p]);
        left = A[right_p--];
        if (left_p > right_p) break;

        ans_center_min += abs(right - A[left_p]);
        right = A[left_p++];
        if (left_p > right_p) break;

        ans_center_min += abs(left - A[left_p]);
        left = A[left_p++];
        if (left_p > right_p) break;
    }

    left = A.back(), right = A.back(), left_p = 0, right_p = N - 2;
    while (true) {
        ans_center_max += abs(left - A[left_p]);
        left = A[left_p++];
        if (left_p > right_p) break;

        ans_center_max += abs(right - A[left_p]);
        right = A[left_p++];
        if (left_p > right_p) break;

        ans_center_max += abs(left - A[right_p]);
        left = A[right_p--];
        if (left_p > right_p) break;

        ans_center_max += abs(right - A[right_p]);
        right = A[right_p--];
        if (left_p > right_p) break;
    }

    cout << max(ans_center_min, ans_center_max) << endl;
}