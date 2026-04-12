#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int64_t MOD_NUM = 1000000000 + 7;
int main()
{
    int64_t N;
    cin >> N;
    vector<int64_t>vec(N);
    int64_t sum_ = 0;
    for (int64_t i=0; i<N; i++) {
        cin >> vec.at(i);
        sum_ += vec[i];
        sum_ %= MOD_NUM;
    }

    int64_t ans = 0;
    for (int64_t i=0; i<N; i++) {
        sum_ -= vec[i];
        if (sum_ < 0) sum_ += MOD_NUM;
        ans += vec[i] * sum_;
        ans %= MOD_NUM;
    }

    cout << ans << endl;
    return 0;
}