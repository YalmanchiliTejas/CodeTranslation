#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
// #define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

int h, w;
string s;

signed main(){
    while(1){
        cin >> s;
        if(s == "#") break;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        char t[11][11];
        int p = 0, q = 0;
        rep(i, 0, s.size()){
            if(s[i] == 'b'){
                t[p][q] = 'b';
                q++;
            }else if(s[i] == '/'){
                p++; q = 0;
            }else if('0' <= s[i] && s[i] <= '9'){
                rep(j, 0, (int)(s[i] - '0')){
                    t[p][q++] = '.';
                }
            }
        }
        p++;
        // rep(i, 0, p){
        //     rep(j, 0, q){
        //         cout << t[i][j];
        //     }
        //     cout << endl;
        // }
        string res = "";
        swap(t[a][b], t[c][d]);
        rep(i, 0, p){
            int now = 0;
            t[i][q] = '!';
            rep(j, 0, q + 1){
                if(j == q && now != 0){
                    res += (char)('0' + now);
                }
                if(now == 0){
                    if(t[i][j] == '.'){
                        now = 1;
                    }else if(t[i][j] == 'b'){
                        res += t[i][j];
                    }
                }else{
                    if(t[i][j] == '.') now++;
                    else if(t[i][j] == 'b'){
                        res += (char)('0' + now);
                        res += "b";
                        now = 0;
                    }
                }
            }
            if(i != p - 1) res += "/";
        }
        cout << res << endl;
    }
}