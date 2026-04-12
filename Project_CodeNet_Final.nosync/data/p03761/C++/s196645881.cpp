#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using vll = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using vvb = vector<vector<bool>>;
using vvll = vector<vector<long long>>;
using pii = pair<int, int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define reps(i,n) for(int i = 1; i <= (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define rreps(i,n) for(int i = (int)(n); i > 0; i--)
#define FOR(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RFOR(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define call(x) (x).cbegin(), (x).cend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if (b<a) {a=b; return 1;} return 0;}
const int INF = INT_MAX;
const int MOD = 1000000007;
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int main() {
    int n;
    cin >> n;
    vs s(n);
    rep(i, n) cin >> s[i];
    map<char, int> dict;
    rep(i, n) {
        
        if (i == 0) rep(j, s[i].size()) {
            int x = count(s[i].cbegin(), s[i].cend(), s[i][j]);
            if (dict.count(s[i][j])) {
                chmin(dict[s[i][j]], x);
            } else if (i == 0) {
                dict[s[i][j]] = x;
            }
        }
        else {
            for (auto p : dict) {
                int x = count(s[i].cbegin(), s[i].cend(), p.first);
                if (x > 0) {
                    chmin(dict[p.first], x);
                } else {
                    dict.erase(p.first);
                }
            }
        }
    }
    string ans = "";
    for (char c = 'a' ; c <= 'z'; c++) {
        if (dict.count(c)) {
            rep(i, dict[c]) ans += c;
        }
    }
    cout << ans << endl;
}