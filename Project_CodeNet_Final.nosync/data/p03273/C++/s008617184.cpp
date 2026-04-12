#include <bits/stdc++.h>
#define rep(i, a, n) for(ll i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    
    rep(i, 0, h) cin >> s[i];
    rep(i, 0, h){
        bool flag = true;
        rep(j, 0, w){
            if(s[i][j] == '#'){
                flag = false;
                break;
            }
        }
        if(flag){
            rep(j, 0, w){
                s[i][j] = '0';
            }
        }
    }
    rep(i, 0, w){
        bool flag = true;
        rep(j, 0, h){
            if(s[j][i] == '#'){
                flag = false;
                break;
            }
        }
        if(flag){
            rep(j, 0, h){
                s[j][i] = '0';
            }
        }
    }
    rep(i, 0, h){
        bool flag = false;;
        rep(j, 0, w){
            if(s[i][j] == '0') continue;
            else{
                cout << s[i][j];
                flag = true;
            }
        }
        if(flag) cout << endl;
    }
    return 0;
}
