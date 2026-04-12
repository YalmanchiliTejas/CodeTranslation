#include <bits/stdc++.h>
using namespace std;
#define rep(i,l,n) for(int i = l; i < n; ++i)

int main() {
    int n;
    int ans = 0;
    int h,bh = -1;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> h;

        if(h >= bh){
            ans++;
            bh = h;
        }
    }

    cout << ans << endl;
}
