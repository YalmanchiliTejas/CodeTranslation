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
    string s;
    cin >> s;
    
    const string pattern[] = {"SS", "SW", "WS", "WW"};
    
    rep(i, 4) {
        vector<char> ans(n + 1, '*');
        ans[n] = '\0';
        rep(ii, pattern[i].length()) ans[ii] = pattern[i][ii];
        bool correct;
        
        reps(ii, 1, n - 1) {
            if (
                ((s[ii] == 'o') && (ans[ii] == 'S')) ||
                ((s[ii] == 'x') && (ans[ii] == 'W'))
            ) {
                ans[ii + 1] = ans[ii - 1];
            }
            else {
                ans[ii + 1] = ((ans[ii - 1] == 'S') ? 'W' : 'S');
            }
        }
        
        reps(ii, n - 1, n + 1) {
            int l = ((ii == 0) ? n - 1 : ii - 1);
            int c = ii % n;
            int r = (ii + 1) % n;
            
            if (
                ((ans[c] == 'S') && (s[c] == 'o')) ||
                ((ans[c] == 'W') && (s[c] == 'x'))
            ) {
                correct = (ans[l] == ans[r]);
            }
            else {
                correct = (ans[l] != ans[r]);
            }
            
            if (!correct) {
                break;
            }
        }
        
        if (correct) {
            printf("%s\n", &ans[0]);
            return 0;
        }
    }
    
    printf("%d\n", -1);
    return 0;
}
