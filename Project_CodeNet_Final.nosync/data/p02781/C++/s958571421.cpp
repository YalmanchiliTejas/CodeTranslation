#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

ll dp[105][2][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    int K;
    cin >> s >> K;
    int n = sz(s);
    dp[0][0][0] = 1;
    rep(i, n) {
        rep(j, 2) {
            rep(k, 4) {
                for (int l = 0; l <= (j == 1 ? 9 : (s[i]-'0')); ++l) {
                    if (k + (l != 0) >= 4) continue;
                    dp[i+1][j || (l < (s[i]-'0'))][k + (l != 0)] += dp[i][j][k]; 
                }
            }
        }
    }
    cout << dp[n][0][K] + dp[n][1][K] << endl;
}