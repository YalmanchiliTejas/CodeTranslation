#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF 1E18



int main(){
    int n;
    cin>>n;
    int h[n];
    rep(i,n) cin>>h[i];

    int ans = 1;
    rep2(i,1,n){
        bool flag = true;
        rep(j,i){
            if(h[i] - h[j] >= 0) continue;
            else{
                flag = false;
                break;
            }
        }
        if(flag) ++ans;
    }

    cout << ans << endl;
    return 0;
}