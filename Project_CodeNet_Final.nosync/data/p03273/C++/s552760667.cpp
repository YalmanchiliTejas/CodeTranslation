#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int h,w;
    cin >> h >> w;
    vector<string> masu(110);
    vector<bool>hantei_h(110);
    vector<bool>hantei_w(110);
    rep(i,h) cin >> masu[i];
    rep(i,h){
        rep(j,w){
            if(masu[i][j] == '#'){
                hantei_h[i] = true;
                hantei_w[j] = true;
            }
        }
    }
    rep(i,h){
        if(hantei_h[i]){
        rep(j,w){
            if( hantei_w[j]) cout << masu[i][j];
        }
        cout << endl;
        }
    }
    return 0;
    
}