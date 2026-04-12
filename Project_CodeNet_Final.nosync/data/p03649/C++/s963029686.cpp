#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

using lli = long long int;

std::vector<lli> A;

// k (1, 1, ..., -n, 1)

int main(void){
    int n; scanf("%d", &n);
    A.resize(n); REP(i, n) scanf("%lld", &A[i]);

    lli res = 0;
    while(true){
        lli cnt = 0;
        REP(i, n) cnt += (A[i] >= 0 ? A[i] / n : 0);
        if(cnt == 0) break;
        // x回の操作のうち, y回選ばれる => (x-y) - yn
        REP(i, n){
            lli proc = A[i] / n;
            lli diff = (cnt - proc) - proc * n;
            A[i] += diff;
        }
        res += cnt;
    }

    printf("%lld\n", res);

    return 0;
}
