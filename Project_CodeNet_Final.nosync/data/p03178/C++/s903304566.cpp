#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define MOD 1000000007
template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

void add(long long &x, long long y){ x = (x + y) % MOD; }
long long dp[100001][101][2];

int main(){
    string K;
    int D;
    cin >> K >> D;
    int N = K.size();
    dp[0][0][0] = 1;
    for(int i=0; i<N; i++){
        int dig = K[i] - '0';
        REP(j, D) REP(k, 10){
            add(dp[i+1][(j+k)%D][1], dp[i][j][1]);
            if(k == dig)
                add(dp[i+1][(j+k)%D][0], dp[i][j][0]);
            if(k < dig)
                add(dp[i+1][(j+k)%D][1], dp[i][j][0]);
        }
    }
    long long ans = (dp[N][0][0] + dp[N][0][1]) % MOD;
    add(ans, MOD-1);
    cout << ans << endl;
    return 0;
}