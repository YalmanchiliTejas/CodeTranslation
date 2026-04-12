#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAX 105

int n[MAX], dp[MAX][4][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    int k;
    cin >> s >> k;

    for (int i=1; i<=s.length(); i++)
        n[MAX-i] = s[s.length()-i] - '0';

    dp[0][0][1] = 1;
    for (int i=1; i<MAX; i++)
        for (int j=0; j<=k; j++) {
            if (j > 0) {
                dp[i][j][0] += dp[i-1][j-1][0] * 9 + (n[i] > 0 ? dp[i-1][j-1][1] * (n[i] - 1) : 0);
                dp[i][j][1] += (n[i] > 0 ? dp[i-1][j-1][1] : 0);
            }
            dp[i][j][0] += dp[i-1][j][0];
            dp[i][j][n[i] == 0] += dp[i-1][j][1];
        }

    cout << dp[MAX-1][k][0] + dp[MAX-1][k][1] << "\n";

    return 0;
}
