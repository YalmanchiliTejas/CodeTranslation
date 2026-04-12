#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H, max_H, ans;
    cin >> N; max_H = 0; ans = 0;
    for (int i=0; i<N; i++) {
        cin >> H;
        if (H >= max_H){
            ans++;
            max_H = H;
        }
    }
    cout << ans << endl;
}