#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;
using P  = pair<ll,ll>;

int main(){
    int n;
    cin >> n;
    int h;
    int hmax = 0;
    int ans = 0;
    rep(i,n){
        cin >> h;
        if(h>=hmax)ans++;
        hmax = max(hmax, h);
    }
    
    cout << ans << endl;
    
    return 0;
}