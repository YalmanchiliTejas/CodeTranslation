#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll min_price = 1e18;
    for(int c_num = 0; c_num <= 2 * max(X,Y); c_num = c_num + 2){
        ll x = max(0, X - c_num / 2);
        ll y = max(0, Y - c_num / 2);
        //cout << min_price <<endl;
        min_price = min(min_price, x * A + y * B + c_num * C);
    }
    cout << min_price << endl;
}