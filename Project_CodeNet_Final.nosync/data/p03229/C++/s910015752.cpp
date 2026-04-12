#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int N;
    cin >> N;

    long int A[100010];
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    // for (int i=0; i<N; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    sort(A, A+N);

    // for (int i=0; i<N; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    long int ans1 = 0;
    long int ans2 = 0;
    int left, right;
    int itr_l, itr_r;

    long int B[100010];
    bool state = false;

    B[N/2] = A[0];
    left = N/2 - 1;
    right = N/2 + 1;
    itr_l = 1;
    itr_r = N - 1;
    for (int i=1; i<(N+2)/2; i++) {
        if (state) {
            if (left >= 0) {
                B[left] = A[itr_l];
                left--;
                itr_l++;
            }
            if (right < N) {
                B[right] = A[itr_l];
                right++;
                itr_l++;
            }
        } else {
            if (left >= 0) {
                B[left] = A[itr_r];
                left--;
                itr_r--;
            }
            if (right < N) {
                B[right] = A[itr_r];
                right++;
                itr_r--;
            }
        }
        state = !state;
    }


    // for (int i=0; i<N; i++) {
    //     cout << B[i] << " ";
    // }
    // cout << endl;

    for (int i=1; i<N; i++) {
        ans1 += abs(B[i] - B[i-1]);
    }

    B[N/2] = A[N-1];
    left = N/2 - 1;
    right = N/2 + 1;
    itr_l = 0;
    itr_r = N - 2;
    state = true;
    for (int i=1; i<(N+2)/2; i++) {
        if (state) {
            if (left >= 0) {
                B[left] = A[itr_l];
                left--;
                itr_l++;
            }
            if (right < N) {
                B[right] = A[itr_l];
                right++;
                itr_l++;
            }
        } else {
            if (left >= 0) {
                B[left] = A[itr_r];
                left--;
                itr_r--;
            }
            if (right < N) {
                B[right] = A[itr_r];
                right++;
                itr_r--;
            }
        }
        state = !state;
    }


    // for (int i=0; i<N; i++) {
    //     cout << B[i] << " ";
    // }
    // cout << endl;

    for (int i=1; i<N; i++) {
        ans2 += abs(B[i] - B[i-1]);
    }

    // cout << "ans1 : " << ans1 << endl;
    // cout << "ans2 : " << ans2 << endl;

    if (ans1 > ans2) {
        cout << ans1 << endl;
    } else {
        cout << ans2 << endl;
    }

    return 0;
}
