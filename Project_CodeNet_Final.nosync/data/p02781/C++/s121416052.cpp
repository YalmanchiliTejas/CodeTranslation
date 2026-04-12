#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int mod = 1e9 + 7;
const int inf = 2e18;

signed main() {
    string S;
    int K;
    cin >> S >> K;
    int N = S.length();
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(4, vector<int>(2, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) for (int j = 0; j < 4; j++) for (int k = 0; k < 2; k++) {
        int base = S[i] - '0';
        for (int digit = 0; digit < 10; digit++) {
            int nexti = i + 1, nextj = j, nextk = k;
            if (digit != 0) ++nextj;
            if (nextj > K) continue;
            if (k == 0) {
                if (digit > base) continue;
                if (digit < base) nextk = 1;
            }
            dp[nexti][nextj][nextk] += dp[i][j][k];
        }
    }
    cout << dp[N][K][0] + dp[N][K][1] << endl;
}

