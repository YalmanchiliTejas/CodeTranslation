#include <iostream>
#include <vector>
using namespace std;

long long X, M;

void next(long long &a) { a = (a == -1) ? X : (a * a) % M; }

int main() {
    long long N; cin >> N >> X >> M;
    vector<bool> seen(M, false);
    long long cycle_detect_i = -1;
    long long cycle_detect_A = -1;
    long long A = -1;
    for (int i = 1; i <= N; ++i) {
        next(A);
        if (seen[A]) {
            cycle_detect_i = i;
            cycle_detect_A = A;
            break;
        }
        seen[A] = true;
    }
    A = -1;
    vector<long long> cycle_csum(M + 1, 0);
    long long ans = -1;
    long long path_sum = 0;
    int path_len = 0;
    for (int i = 1; i <= N; ++i) {
        next(A);
        path_sum += A;
        path_len++;
        if (A == cycle_detect_A) {
            int cycle_len = cycle_detect_i - i;
            for (int j = 1; j <= cycle_len; ++j) {
                next(A);
                cycle_csum[j] = cycle_csum[j - 1] + A;
            }
            N -= path_len;
            ans = path_sum 
                   + cycle_csum[cycle_len] * (N / cycle_len) 
                    + cycle_csum[N % cycle_len];
            break;
        }
    }
    if (ans == -1) ans = path_sum;
    cout << ans << endl;
}