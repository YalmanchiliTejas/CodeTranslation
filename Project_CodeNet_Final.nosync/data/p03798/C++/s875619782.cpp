#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    s += s;
    string ans;
    for(int i = 0; i < 4; i++){
        ans = "";
        if(i == 0) ans += "SS";
        if(i == 1) ans += "SW";
        if(i == 2) ans += "WS";
        if(i == 3) ans += "WW";
        for(int j = 1; j <= n+1; j++){
            if(s[j] == 'o'){
                if(ans[j] == 'S'){
                    ans += ans[j-1];
                }
                else{
                    if(ans[j-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
            }
            else{
                if(ans[j] == 'S'){
                    if(ans[j-1] == 'S') ans += 'W';
                    else ans += 'S';
                }
                else{
                    ans += ans[j-1];
                }
            }
        }
        if(ans[0] == ans[n] && ans[1] == ans[n+1]){
            cout << ans.substr(0, n) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}