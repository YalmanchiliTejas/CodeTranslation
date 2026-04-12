#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> H(n);
    for (int i = 0; i < n; i++) cin >> H[i];
    int ma = 0, ans = 0;
    for (auto &h: H){
        if (ma <= h) {
            ans++;
            ma = h;
        }
    }

    cout << ans << endl;
}