#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    bool isVisible = true;
    int ans = 0;
    rep(i, n) cin >> h[i];
    rep(i,n){
        for (int j = 0; j < i; j++){
            if(h[j]>h[i]){
                isVisible = false;
            }
        }
        if(isVisible){
            ans++;
            //cout << ans << endl;
        }
        isVisible = true;
    }
    cout << ans << endl;
}