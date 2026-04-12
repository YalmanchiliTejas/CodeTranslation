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

    int ans = 0;
    int max_height = -1;
    rep(i,n){
        if(h[i] >= max_height){
            ans++;
            max_height = h[i];
        }
    }

    cout << ans << endl;
    return 0;
}