#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans;
    int H[256] = {};

    cin >> n;
    ans = n;
    for (int i = 0; i < n; i++){
        cin >> H[i];
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if ( H[i] <  H[j] ) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
}