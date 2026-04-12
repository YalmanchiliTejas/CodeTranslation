#include <iostream>
using namespace std;
typedef long long ll;
ll n;
string str, ans[4];
int main(void){
    // Your code here!
    cin >> n >> str;
    ans[0] += "SS", ans[1] += "SW", ans[2] += "WS", ans[3] += "WW";
    for (ll i = 0; i < 4; i++){
        bool res = true;
        for (ll j = 1; j < n - 1; j++){
            if ((str[j] == 'o' && ans[i][j] == 'S') || (str[j] == 'x' && ans[i][j] == 'W')){
                ans[i] += ans[i][j - 1];
            } else {
                ans[i] += (ans[i][j - 1] == 'S' ? 'W' : 'S');
            }
        }
        if ((ans[i][0] == 'S' && str[0] == 'o') || (ans[i][0] == 'W' && str[0] == 'x')){
            if (ans[i][1] != ans[i][n - 1]) res = false;
        } else {
            if (ans[i][1] == ans[i][n - 1]) res = false;
        }
        if ((ans[i][n - 1] == 'S' && str[n - 1] == 'o') || (ans[i][n - 1] == 'W' && str[n - 1] == 'x')){
            if (ans[i][0] != ans[i][n - 2]) res = false;
        } else {
            if (ans[i][0] == ans[i][n - 2]) res = false;
        }
        if (!res) continue;
        cout << ans[i] << endl;
        return 0;
    }
    cout << -1 << endl;
}
