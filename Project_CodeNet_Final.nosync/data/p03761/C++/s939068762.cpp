#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) cin >> s[i];

    for(int i = 0; i < 26; i++) {
        char tmp = 'a' + i;
        int ma = inf;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < s[i].size(); j++) {
                if (s[i][j] == tmp) cnt++;
            }
            chmin(ma, cnt);
        }

        REP(i, ma) cout << tmp;
    }

    cout << endl;
    

    return 0;
}