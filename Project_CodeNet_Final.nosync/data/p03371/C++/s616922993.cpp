#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

int main(){
    i64 A ,B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    i64 ans = 1e18;
    for(i64 i = 0; i <= max(X, Y); i++){
        i64 res = C*2*i + A*max(X - i, 0l) + B*max(Y - i, 0l);
        ans = min(ans, res);
    }

    cout << ans << endl;
}