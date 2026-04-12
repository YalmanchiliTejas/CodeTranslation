#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {    
    int n; cin >> n;
    vector<string> S(n);
    rep(i, n) cin >> S[i];

    vector<char> alp;
    for(char c = 'a'; c <= 'z'; c++)
        alp.push_back(c);

    vector<vector<int>> count(n, vector<int>(26, 0));
    rep(i, n){
        rep(j, S[i].size()){
            int index = S[i][j] - 'a';
            count[i][index]++;
        }
    }

    rep(i, 26){
        int mx = INF;
        rep(j, n){
            chmin(mx, count[j][i]);
        }
        rep(j, mx){
            cout << alp[i];
        }
    }
    cout << ln;
} 
