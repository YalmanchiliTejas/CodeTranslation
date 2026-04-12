#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(),(x).end()

#define READ(x) (cin >> (x))

#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))

int main() {
    // get values from input
    int N;
    READ(N);

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        READ(A[i]);
    }

    // main procedure
    vector<ll> max_not_take_last(N+1);
    vector<ll> max_take_last(N+1);
    vector<ll> max_all(N+1);

    vector<ll> max_one_more(N+1);

    max_one_more[1] = A[0];
    for (int i = 2; i < N+1; ++i) {
        if (i % 2 == 0) {
            max_not_take_last[i] = max_one_more[i - 1];
            max_take_last[i] = max_not_take_last[i - 1] + A[i - 1];


        } else {
            max_not_take_last[i] = max_all[i - 1];
            max_take_last[i] = max_all[i - 2] + A[i - 1];

            max_one_more[i] = max_one_more[i - 2] + A[i - 1];
        }
        max_all[i] = max(max_not_take_last[i], max_take_last[i]);
    }

    // output
    WRITE(max_all[N]);

    return 0;
}
