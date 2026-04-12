#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using i64 = int64_t;
using u64 = uint64_t;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

constexpr int64_t MOD = 1'000'000'007LL;

#define INT(NAME) int NAME; cin>>NAME;
#define INT64(NAME) int64_t NAME; cin>>NAME;
#define VECTOR(NAME, TYPE, SIZE) std::vector<TYPE> NAME((SIZE));\
    for(int xxxx_i=0; xxxx_i<SIZE; xxxx_i++) cin>>NAME[xxxx_i];
#define FOR(i, start, end) for(i64 i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)    


void solve() {
    INT(N)
    VECTOR(A,int,N)

    if (N==2) {
        cout<<max(A[0], A[1])<<endl;
        return;
    }

    if (N==3) {
        cout<<max(A[0]+A[2], A[1])<<endl;
        return;
    }

    i64 ans;
    if (N&1) {
        vector<i64> dp(A.begin(), A.begin()+3);
        vector<i64> next(3);
        for(int i=2; i+2<N; i+=2) {
            next[0] = A[i] + dp[0];
            next[1] = A[i+1] + max(dp[0], dp[1]);
            next[2] = A[i+2] + max(max(dp[0], dp[1]), dp[2]);
            swap(dp, next);
        }
        ans = *max_element(dp.begin(), dp.end());
    }
    else {
        vector<i64> dp(A.begin(), A.begin()+2);
        vector<i64> next(2);
        for(int i=2; i+1<N; i+=2) {
            next[0] = A[i] + dp[0];
            next[1] = A[i+1] + max(dp[0], dp[1]);
            swap(dp, next);
        }
        ans = *max_element(dp.begin(), dp.end());
    }
    cout<<ans<<endl;
}

int main() {
    solve();

    return 0;
}