#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    int n;
    cin >> n;
    int h[100];
    rep(i, n){
        cin >> h[i];
    }

    int max_h = h[0];
    int ans = 1;
    for(int i=1; i<n; i++){
        if(max_h <= h[i]){
            max_h = h[i];
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}