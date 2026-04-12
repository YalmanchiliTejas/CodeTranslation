#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int res = 0;
    int t = min(A+B, 2*C);
    while(X>0 && Y>0) {
        res += t;
        X--; Y--;
    }

    if(X==0 && Y>0) {
        int tt = min(B, 2*C);
        while(Y>0) {
            res += tt;
            Y--;
        }
    } else if(Y==0 && X>0) {
        int tt = min(A, 2*C);
        while(X>0) {
            res += tt;
            X--;
        }
    }

    cout << res << endl;
    return 0;
}