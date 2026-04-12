#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    short h,w,ans = 0;
    cin >> h >> w;
    char ai[w];
    rep(i,h) {
        cin >> ai;
        rep(j,w) if (ai[j] == '#') ans ++;
    }
    if (ans == h+w-1) cout << "Possible\n";
    else cout << "Impossible\n";
}