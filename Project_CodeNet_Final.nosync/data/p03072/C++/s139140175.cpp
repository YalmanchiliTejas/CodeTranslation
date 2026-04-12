#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> H(N);
    int ans = 1;
    bool canSee=true;
    for (int i=0; i<N; i++) cin >> H.at(i);
    for (int i=1; i<N; i++) {
        canSee=true;
        for (int j=0; j<i; j++) {
            if (H.at(i)<H.at(j)) {
                canSee=false;
                break;
            }
        }
        if (canSee) ans++;
    }
    cout << ans;
}