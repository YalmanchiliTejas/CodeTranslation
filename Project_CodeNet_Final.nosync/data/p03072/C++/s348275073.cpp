#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define _Pi 3.1415926535
#define _MOD = 1e9+7;
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int ans = 0, max = h[0];

    rep(i,n){
        if(h[i] >= max){
            ++ans;
            max = h[i];
        }
    }

    cout << ans << endl;

    return 0;
}
