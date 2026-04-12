#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
typedef long long ll;

int main() {
    int h,w; cin >> h >> w;
    vector<vector<char>> a(h,vector<char> (w));
    bool t[h] = {false};
    bool y[w] = {false};
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
            if(a[i][j] == '#'){
                t[i] = true;
                y[j] = true;
            }
        }
    }
    rep(i,h){
        if(t[i]){
            rep(j,w){
                if(y[j]){
                    cout << a[i][j];
                }
            }
        }else{
            continue;
        }
        cout << endl;
    }
}