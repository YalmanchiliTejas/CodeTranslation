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

    long long ans[2] = {};
    int left = A.front(), right = A.front(), left_p = 1, right_p = N - 1;
    while (true) {
        ans[0] += abs(A[right_p] - right);
        right = A[right_p];
        right_p--;
        if (right_p < left_p) break;

        ans[0] += abs(A[right_p] - left);
        left = A[right_p];
        right_p--;
        if (right_p < left_p) break;

        ans[0] += abs(A[left_p] - right);
        right = A[left_p];
        left_p++;
        if (right_p < left_p) break;

        ans[0] += abs(A[left_p] - left);
        left = A[left_p];
        left_p++;
        if (right_p < left_p) break;
    }

    left = A.back();
    right = A.back();
    left_p = 0;
    right_p = N - 2;
    while (true) {
        ans[1] += abs(A[left_p] - left);
        left = A[left_p];
        left_p++;
        if (right_p < left_p) break;

        ans[1] += abs(A[left_p] - right);
        right = A[left_p];
        left_p++;
        if (right_p < left_p) break;

        ans[1] += abs(A[right_p] - left);
        left = A[right_p];
        right_p--;
        if (right_p < left_p) break;

        ans[1] += abs(A[right_p] - right);
        right = A[right_p];
        right_p--;
        if (right_p < left_p) break;
    }

    cout << max(ans[0], ans[1]) << endl;
}