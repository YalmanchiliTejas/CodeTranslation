#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
#define endl "\n"
#define int long long
typedef long long ll;
using namespace std;

int solve(string& s, string& mask, int i, bool gr) {
    if(i == sz(mask)) {
        return 1;
    }
    if(mask[i] == '0') {
        return solve(s, mask, i + 1, gr || (s[i] > '0'));
    } else {
        if(gr) {
            return 9 * solve(s, mask, i + 1, gr);
        } else if(s[i] == '0') {
            return 0;
        } else {
            return solve(s, mask, i + 1, false) + (s[i] - '0' - 1) * solve(s, mask, i + 1, true);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    int n = sz(s);
    int ans = 0;
    if(k == 1) {
        rep(i, 1, n) {
            string mask(n, '0');
            mask[i - 1] = '1';
            ans += solve(s, mask, 0, false);
        }
    } else if(k == 2) {
        rep(i, 1, n) {
            rep(j, i + 1, n) {
                string mask(n, '0');
                mask[i - 1] = '1';
                mask[j - 1] = '1';
                ans += solve(s, mask, 0, false);
            }
        }
    } else if(k == 3) {
        rep(i, 1, n) {
            rep(j, i + 1, n) {
                rep(k, j + 1, n) {
                    string mask(n, '0');
                    mask[i - 1] = '1';
                    mask[j - 1] = '1';
                    mask[k - 1] = '1';
                    ans += solve(s, mask, 0, false);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
