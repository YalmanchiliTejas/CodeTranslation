#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
int dp[5][105][2];
int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    dp[0][0][0] = 1;
    rep(i,k+1){
        rep(j,s.size()){
            int x = s[j] - '0';
            rep(k,2){
//                show(i,j,k,x,dp[i][j][k]);
                if(k == 0){
                    for(int l = 0; l < x; l++){
                        dp[i + (l == 0 ? 0 : 1)][j+1][1] += dp[i][j][k];
                    }
                    dp[i + (x == 0 ? 0 : 1)][j+1][0] += dp[i][j][k];
                }else{
                    dp[i][j+1][1] += dp[i][j][1];
                    if(i+1<=3)dp[i+1][j+1][1] += dp[i][j][1]*9;
                }
            }
        }
    }
    cout << dp[k][s.size()][0] + dp[k][s.size()][1] << endl;
}
