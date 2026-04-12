#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

#define MAX_N 100000

int N;
unsigned long int A[MAX_N];
unsigned long long int res;

unsigned long int solve( bool g ) {
    int l=0, r=N-1;
    unsigned long int lv, rv;
    if (g) {
    // res += abs(A[r] - A[l]) + abs(A[r] - A[l+1]);
        res = abs(A[l] - A[r]) + abs(A[l] - A[r-1]);
        lv = A[r];
        rv = A[r-1];
    // l += 2;
    // --r;
        ++l;
        r -= 2;
    // bool f = false; // true -> lv, rv は l で決めた, つぎはrからとる
    } else {
        res = abs(A[r] - A[l]) + abs(A[r] - A[l+1]);
        lv = A[l];
        rv = A[l+1];
        l += 2;
        --r;
    }
    bool f = !g;

    while (l <= r) {
        if (f) {
            // if (lv < rv) {
                res += abs(lv - A[r]) + abs(rv - A[r-1]);
                lv = A[r];
                rv = A[r-1];
            /* } else {
                res += abs(rv - A[r]) + abs(lv - A[r-1]);
                lv = A[r-1];
                rv = A[r];
             } */
            r -= 2;
        } else {
            // if (lv > rv) {
                res += abs(rv - A[l]) + abs(lv - A[l+1]);
                rv = A[l];
                lv = A[l+1];
            /* } else {
                res += abs(rv - A[l+1]) + abs(lv - A[l]);
                rv = A[l+1];
                lv = A[l];
            } */
            l += 2;
        }
        f = !f;
    }
    return res;
}

int main() {
    std::cin >> N;
    for (int i=0; i<N; i++) {
        std::cin >> A[i];
    }
    if (N == 2) {
        std::cout << abs(A[1] - A[0]) << std::endl;
    } else {
        unsigned long long int result;
        std::sort(A, A+N);
        result = std::max(solve(true), solve(false) );
        std::cout << result << std::endl;
    }
    return 0;
}
