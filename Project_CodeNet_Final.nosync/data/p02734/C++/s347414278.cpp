#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 998244353

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

void add(long long &x, long long y){
    x = (x + y) % MOD;
}

int main(){
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(S+1, vector<long long>(3)));

    dp[0][0][0] = 1;
    for(int i=0; i<N; i++){
        dp[i+1] = dp[i];
        add(dp[i+1][0][1], dp[i+1][0][0]);
        for(int j=S-A[i]; j>=0; j--){
            add(dp[i+1][j+A[i]][1], dp[i+1][j][1]);
        }
        for(int j=0; j<=S; j++){
            add(dp[i+1][j][2], dp[i+1][j][1]);
        }
    }
    long long ans = dp[N][S][2];
    cout << ans << endl;
    return 0;
}