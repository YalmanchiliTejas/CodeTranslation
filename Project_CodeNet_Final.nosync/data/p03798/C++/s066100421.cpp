#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> inline T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }







int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    // 解説みた
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    
    rep(i, 2) rep(j, 2) {
        string t;
        t += (i == 0 ? 'S' : 'W');
        t += (j == 0 ? 'S' : 'W');
        
        rep3(k, 2, sz(s)) { // s[k]求めていく
            if (t[k - 1] == 'S') { // tの末尾が羊か
                if (s[k - 1] == 'o') {
                    t += t[k - 2];
                } else {
                    t += (t[k - 2] == 'S' ? 'W' : 'S');
                }
            } else {
                if (s[k - 1] == 'o') {
                    t += (t[k - 2] == 'S' ? 'W' : 'S');
                } else {
                    t += t[k - 2];
                }
            }
        }
        
        // 手前の2つから最後の文字まで求まった
        // 最後の2つから0番目, 最後と0番目から1番目もあってるか
        
        int flg = 0;
        
        if (t[n - 1] == 'S') {
            if (s[n - 1] == 'o') {
                if (t[n - 2] != t[0]) flg = 1;
            } else {
                if (t[n - 2] == t[0]) flg = 1;
            }
        } else {
            if (s[n - 1] == 'o') {
                if (t[n - 2] == t[0]) flg = 1;
            } else {
                if (t[n - 2] != t[0]) flg = 1;
            }
        }
        
        if (t[0] == 'S') {
            if (s[0] == 'o') {
                if (t[n - 1] != t[1]) flg = 1;
            } else {
                if (t[n - 1] == t[1]) flg = 1;
            }
        } else {
            if (s[0] == 'o') {
                if (t[n - 1] == t[1]) flg = 1;
            } else {
                if (t[n - 1] != t[1]) flg = 1;
            }
        }
        
        if (flg == 0) {
            cout << t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
