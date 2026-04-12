#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1'000'000'007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

const long long INF = 1LL<<60;

int main(){
    long long N;
    cin >> N;
    vector<long long> A(N);
    REP(i, N) cin >> A[i];
    if(N == 2){
        cout << max(A[0], A[1]) << endl;
        return 0;
    }

    vector<vector<long long>> dp(N, vector<long long>(3, -INF));
    dp[0][0] = A[0];
    dp[1][1] = A[1];
    dp[2][2] = A[2];
    for(int i=0; i<N; i++){
        if(dp[i][0] != -INF){
            if(i+2<N) dp[i+2][0] = max(dp[i+2][0], dp[i][0] + A[i+2]);
            if(i+3<N) dp[i+3][1] = max(dp[i+3][1], dp[i][0] + A[i+3]);
            if(i+4<N) dp[i+4][2] = max(dp[i+4][2], dp[i][0] + A[i+4]);
        }
        if(dp[i][1] != -INF){
            if(i+2<N) dp[i+2][1] = max(dp[i+2][1], dp[i][1] + A[i+2]);
            if(i+3<N) dp[i+3][2] = max(dp[i+3][2], dp[i][1] + A[i+3]);
        }
        if(dp[i][2] != -INF){
            if(i+2<N) dp[i+2][2] = max(dp[i+2][2], dp[i][2] + A[i+2]);
        }
    }
    long long ans = -INF;
    if(N%2==0) ans = max(dp[N-1][1], dp[N-2][0]);
    if(N%2==1){
        ans = max(ans, dp[N-1][2]);
        ans = max(ans, dp[N-2][1]);
        ans = max(ans, dp[N-3][0]);
    }
    cout << ans << endl;
    return 0;
}
