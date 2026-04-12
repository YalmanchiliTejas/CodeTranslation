#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    map<char, int> cm;
    string ans;
    
    rep(i, n) {
        string s;
        cin >> s;
        map<char, int> tmp;
        
        if (i == 0) {
            rep(ii, s.length()) {
                cm[s[ii]]++;
            }
        }
        else {
            rep(ii, s.length()) {
                tmp[s[ii]]++;
            }
            
            for (auto u : cm) {
                cm[u.first] = min(u.second, tmp[u.first]);
            }
        }
    }
    
    for (auto u : cm) {
        rep(i, u.second) {
            ans += u.first;
        }
    }
    
    cout << ans << endl;
    return 0;
}
