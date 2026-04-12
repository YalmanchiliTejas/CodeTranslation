#include <bits/stdc++.h>
using namespace std;

int main(){

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int AB = 2 * C;

    long long ans = 1e12;
    for(int i = 0; i <= max(X, Y); i++){
        int x = X - i, y = Y - i;
        long long sum = (AB * i) + (A * max(0, x)) + (B * max(0, y));
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}