#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int N;
ll A[100010];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    ll b = 0;
    ll s = 0;
    sort(A, A + N, greater<>());
    if (N % 2 == 1) {
        if (2 * A[(N-1)/2] > A[(N-1)/2-1] + A[(N-1)/2+1]) {
            for (int i = 0; i < (N - 3) / 2; i++) {
                b += 2 * A[i];
            }
            b += A[(N - 3) / 2] + A[(N - 1) / 2];
            for (int i = 0; i < (N - 1) / 2; i++) {
                s += 2 * A[i + (N + 1) / 2];
            }
        } else {
            for (int i = 0; i < (N - 1) / 2; i++) {
                b += 2 * A[i];
            }
            for (int i = 0; i < (N - 3) / 2; i++) {
                s += 2 * A[i + (N + 3) / 2];
            }
            s += A[(N-1)/2] + A[(N+1)/2];
        }
    } else {
        for (int i = 0; i < N / 2 - 1; i++) {
            b += 2 * A[i];
        }
        b += A[N / 2 - 1];
        for (int i = 0; i < N / 2 - 1; i++) {
            s += 2 * A[i + N / 2 + 1];
        }
        s += A[N / 2];
    }
    cout << b - s << endl;
}