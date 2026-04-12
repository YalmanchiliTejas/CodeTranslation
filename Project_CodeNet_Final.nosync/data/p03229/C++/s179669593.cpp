#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    long int N;
    cin >> N;

    long int A[100010];
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    sort(A, A+N);

    // for (int i=0; i<N; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    long int ans1 = 0;
    long int ans2 = 0;

    if (N%2 == 0) {
        for (int i=0; i<(N/2)-1; i++) {
            ans1 -= 2*A[i];
        }
        ans1 -= A[(N/2)-1];
        ans1 += A[N/2];
        for (int i=(N/2)+1; i<N; i++) {
            ans1 += 2*A[i];
        }
        cout << ans1 << endl;
    } else {
        // ans1
        for (int i=0; i<(N-1)/2-1; i++) {
            ans1 -= 2*A[i];
        }
        ans1 -= A[(N-1)/2-1];
        ans1 -= A[(N-1)/2];
        for (int i=(N-1)/2+1; i<N; i++) {
            ans1 += 2*A[i];
        }
        // ans2
        for (int i=0; i<(N-1)/2; i++) {
            ans2 -= 2*A[i];
        }
        ans2 += A[(N-1)/2];
        ans2 += A[(N-1)/2+1];
        for (int i=(N-1)/2+2; i<N; i++) {
            ans2 += 2*A[i];
        }
        if (ans1 > ans2) {
            cout << ans1 << endl;
        } else {
            cout << ans2 << endl;
        }
    }

    return 0;
}
