#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
    ll h, w;
    cin >> h >> w;
    string a[h];

    rep(i, h){
        cin >> a[i];
    }


    bool check_w[w];
    bool check_h[h];
    rep(i, h){
        bool check = true;
        rep(j, w){
            if(a[i][j] == '#')
                check = false;
        }
        if(check)
            check_h[i] = true;
        else
            check_h[i] = false;
    }
    rep(i, w){
        bool check = true;
        rep(j, h){
            if(a[j][i] == '#')
                check = false;
        }
        if(check)
            check_w[i] = true;
        else
            check_w[i] = false;
    }

    rep(i, h){
        if(check_h[i]) continue;
        rep(j, w){
            if(check_w[j]) continue;
            cout << a[i][j];
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}
