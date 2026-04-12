#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 1; i <= (int)(n); i++)

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int yen = a * x + b * y;
    rep(i, 100000){
        yen = min(yen, 2 * i * c + max(x-i, 0) * a + max(y-i, 0) * b);
    }
    cout << yen << endl;
    return 0;
}
