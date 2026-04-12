#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ans = 1, max = h[0];
    rep(i,n-1) if(max <= h[i+1]){
        ans++;
        max = h[i+1];
    }
    cout << ans << endl;
}