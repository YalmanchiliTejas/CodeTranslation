#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int res = 0;
    rep(i,n){
        bool s = true;
        rep(j,i){
            if(h[j] > h[i]) s = false;
        }
        if(s) res++;
    }
    cout << res << endl;
}