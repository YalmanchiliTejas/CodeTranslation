#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long int ll;
typedef pair<int, int> P;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int h[n];
    rep(i, n) cin >> h[i];
    
    int big = 0;
    int ans = 0;
    
    rep(i, n){
        if(big <= h[i]){
            ans++;
            big = h[i];
        }
    }
    
    cout << ans << endl;

    return 0;
}