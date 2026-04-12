#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int h,w;
    cin>> h >> w;
    vector<bool>ok_h(200);
    vector<bool>ok_w(200);
    vector<string> a(h);
    rep(i,h){
        cin >> a[i];
    }
      

    rep(i,h){
        rep(j,w){
            if(a[i][j] == '#'){
                ok_h[i] = true;
                ok_w[j] = true;
            }
        }
    }
    rep(i,h){
        if(ok_h[i]){
        rep(j,w){
           if(ok_w[j]) cout << a[i][j];
        }
        cout << endl;
    }
}
return 0;
}