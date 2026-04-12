#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
const ll INF = 1LL<<60;
const int INT_INF = 1e9;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main() {
    int n; cin >> n;
    string s[51];
    rep(i, n) cin >> s[i];
    rep(i, n) sort(s[i].begin(), s[i].end());

    string ans = "";
    for (char a = 'a'; a <= 'z'; ++a) {
        int na = 100;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int p = 0; p < s[i].length(); p++) {
                if (s[i][p] == a) tmp++;
            }
            chmin(na, tmp);
        }
        rep(_, na) ans += a;
    }
    cout << ans << endl;
}
