#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int H, W, a = 0;
    string S;
    cin >> H >> W;
    rep(i, H) {
        cin >> S;
        rep(j, W) {
            if (S[j] == '#') a++;
        }
    }
    if (a == H + W - 1) cout << "Possible\n";
    else cout << "Impossible\n";
}