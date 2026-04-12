#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m = 0,cnt = 0;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    rep(i,n){
        if(h[i]>=m){
            cnt += 1;
            m = h[i];
        }
    }
    cout << cnt << endl;
}