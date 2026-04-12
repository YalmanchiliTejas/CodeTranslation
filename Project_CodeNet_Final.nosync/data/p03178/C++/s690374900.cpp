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
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) //cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll dp[10005][2][100];
ll mod = 1e9+7;
int main(){
    string s;
    cin >> s;
    int d;
    cin >> d;
    dp[0][0][0] = 1;
    rep(i,s.size()){
        rep(j,d){
            for(int k = 0; k < s[i]-'0'; k++){
                dp[i+1][1][(j+k)%d] = (dp[i+1][1][(j+k)%d] + dp[i][0][j]) % mod;
            }
            dp[i+1][0][(j+s[i]-'0')%d] = (dp[i+1][0][(j+s[i]-'0')%d] + dp[i][0][j]) % mod;
            for(int k = 0; k <= 9; k++){
                dp[i+1][1][(j+k)%d] = (dp[i+1][1][(j+k)%d] + dp[i][1][j]) % mod;
            }
        }
    }
    cout << (dp[s.size()][0][0] + dp[s.size()][1][0] -1 + mod) % mod << endl;
}