#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    int h[200];
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int ans = 1, mx = h[0];
    for (int i = 1; i < n; i++){
        if (h[i] >= mx){
            ans += 1;
            mx = h[i];
        }
    }

    cout << ans << '\n';

    return 0;
}
