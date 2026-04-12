#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    long long ans = 0;
    if(A + B > 2*C) {
        ans += min(X, Y)*2*C;
        int tmp = min(X, Y);
        X -= tmp; Y -= tmp;
    }
    else {
        ans += min(X, Y)*(A + B);
        int tmp = min(X, Y);
        X -= tmp; Y -= tmp;
    }

    if(X == 0) {
        if( B < 2*C ) ans += Y*B;
        else ans += Y*2*C;
    }
    if(Y == 0) {
        if( A < 2*C ) ans += X*A;
        else ans += X*2*C;
    }

    cout << ans << endl;
    return 0;
}