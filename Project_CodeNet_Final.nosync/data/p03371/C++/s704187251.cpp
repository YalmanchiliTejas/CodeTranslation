#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int main(int argc, char* argv[]){
    int A, B, C, X, Y, ans = 0, m;
    cin >> A >> B >> C >> X >> Y;
    if(2*C < A+B){
        m = min(X, Y);
        ans += 2 * m * C;
        X -= m;
        Y -= m;
    }
    if(2*C < A){
        ans += X * 2 * C;
        X = 0;
    }
    if(2*C < B){
        ans += Y * 2 * C;
        Y = 0;
    }
    ans += X * A;
    ans += Y * B;
    cout << ans << endl;
}
