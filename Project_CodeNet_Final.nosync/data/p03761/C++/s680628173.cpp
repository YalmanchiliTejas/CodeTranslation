#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;
const int mod = 1e9 + 7;
int main() {

    int n;
    cin >> n;
    
    int a[50][26] = {};
    rep(i, n){
        string s;
        cin >> s;
        rep(j, s.length()){
            a[i][s[j]-'a']++;
        }
    }

    string ans = "";
    rep(i, 26){
        int m = mod;
        rep(j, n){
            m = min(m, a[j][i]);
        }
        rep(k, m){
            ans += 'a' + i;
        }
    }
    cout << ans << endl;

    return 0;
}