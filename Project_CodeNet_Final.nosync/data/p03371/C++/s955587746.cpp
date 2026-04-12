/**
 * @author torith
 * @date 2018-10-15
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = A * X + B * Y;

    if (X <= Y) {
        ans = min(ans, X * 2 * C + (Y - X) * B);
        ans = min(ans, Y * 2 * C);
    }else{
        ans = min(ans, Y * 2 * C + (X - Y) * A);
        ans = min(ans, X * 2 * C);
    }

    cout << ans << "\n";

    return 0;
}

