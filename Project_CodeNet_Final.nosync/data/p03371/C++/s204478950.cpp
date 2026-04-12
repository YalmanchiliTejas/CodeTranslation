#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll AB = C * 2;
    ll ans = 1e18;
    for(int i = 0;i <= max(X,Y);i++){
        if(ans > AB * i + max(0,X-i) * A + max(0,Y-i) * B){ans = AB * i + A * max(0,X-i) + B * max(0,Y-i);}
    }
    cout << ans;
}


