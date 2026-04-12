#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
int main(){
    int n; cin >> n;
    vector<int> h(n); rep(i,n) cin >> h[i];
    int hmax = 0;
    int ans = 0;
    rep(i,n){
        if(hmax <= h[i]){
            ans++;
            hmax = h[i];
        }
    }
    cout << ans << endl;
}