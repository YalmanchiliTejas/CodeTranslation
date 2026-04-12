#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "}"; return os; }


int main(){
    LL n;
    cin >> n;
    vector<LL> a(n);
    for(LL i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<vector<LL>> dp(n+2, vector<LL>(3, -1e+15));
    dp[0][0] = 0;
    dp[1][1] = 0;
    for(LL i = 0; i < n; ++i){
        for(LL j = 0; j < 3; ++j){
            // use a[i]
            dp[i+2][j] = max(dp[i+2][j], dp[i][j] + a[i]); 
            // not use a[i]
            if(j+1 < 3){
                dp[i+2][j+1] = max(dp[i+2][j+1], dp[i+1][j]);                  
            }
        }
    }
    LL ans = 0;
    if(n % 2 == 0){
        ans = dp[n+1][1];
    }else{
        ans = dp[n+1][2];
    }
    //cerr << dp << endl;
    cout << ans << endl;
    return 0;
}

