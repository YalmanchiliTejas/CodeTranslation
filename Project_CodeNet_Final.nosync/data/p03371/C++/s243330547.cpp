#include <bits/stdc++.h>
using namespace std;

int A, B, C, X, Y;

int main(){
    cin >> A >> B >> C >> X >> Y;
    int AB = 2 * C;
    long long int ans = LLONG_MAX;
    for (int i = 0; i < 200001; i++){
        long long int price = A * max(X - i, 0) + B * max(Y - i, 0) + AB * i;
        //cout << price << endl;
        ans = min(price, ans);
    }
    cout << ans << endl;
}