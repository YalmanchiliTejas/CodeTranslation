#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int MX, ans;
    MX = ans = 0;
    for(int i = 0; i < n; i++){
        int curr;cin >> curr;
        MX = max(MX,curr);
        ans += (MX <= curr);
    }
    cout << ans << "\n";
    return 0;
}