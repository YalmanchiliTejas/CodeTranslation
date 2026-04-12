#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> pat = {"SS", "SW", "WS", "WW"};
    for(string x : pat){
        vector<char> ans(n);
        ans[0] = x[0];
        ans[1] = x[1];
        for(int i = 1; i < n - 1; i++){
            if(ans[i] == 'S'){
                if(s[i] == 'o') ans[i + 1] = ans[i - 1];
                else{
                    if(ans[i - 1] == 'S') ans[i + 1] = 'W';
                    else ans[i + 1] = 'S';
                }
            }else{
                if(s[i] == 'x') ans[i + 1] = ans[i - 1];
                else{
                    if(ans[i - 1] == 'S') ans[i + 1] = 'W';
                    else ans[i + 1] = 'S';
                }
            }
        }
        if(ans[n - 1] == 'S' && s[n - 1] == 'o' && ans[n - 2] != ans[0]) continue;
        if(ans[n - 1] == 'S' && s[n - 1] == 'x' && ans[n - 2] == ans[0]) continue;
        if(ans[n - 1] == 'W' && s[n - 1] == 'o' && ans[n - 2] == ans[0]) continue;
        if(ans[n - 1] == 'W' && s[n - 1] == 'x' && ans[n - 2] != ans[0]) continue;
        if(ans[0] == 'S' && s[0] == 'o' && ans[n - 1] != ans[1]) continue;
        if(ans[0] == 'S' && s[0] == 'x' && ans[n - 1] == ans[1]) continue;
        if(ans[0] == 'W' && s[0] == 'o' && ans[n - 1] == ans[1]) continue;
        if(ans[0] == 'W' && s[0] == 'x' && ans[n - 1] != ans[1]) continue;
        rep(i, n) cout << ans[i];
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
}