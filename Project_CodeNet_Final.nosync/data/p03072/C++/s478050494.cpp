#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int n;
    cin >> n;
    int h[n];
    rep(i,n) cin >> h[i];

    int top = 0;
    int ans = 0;
    rep(i,n) {
        if (top <= h[i]) ans++;
        top = max(top, h[i]);
    }
    cout << ans << endl;
    return 0;
}
