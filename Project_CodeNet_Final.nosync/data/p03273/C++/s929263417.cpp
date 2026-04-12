#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a;
    rep(i, h){
        string s;
        cin >> s;
        a.push_back(s);
    }
    
    vector<bool> col(h, true), row(w, true);
    rep(i, h){
        rep(j, w){
            if(a[i][j]=='#'){
                col[i] = false;
                row[j] = false;
            }
        }
    }

    rep(i, h){
        if(col[i]){
            continue;
        }
        rep(j, w){
            if(row[j]){
                continue;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}