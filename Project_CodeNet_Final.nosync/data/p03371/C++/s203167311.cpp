#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
#define INF 1001001001
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll max_pizza = max(x, y);
    ll cost = INF;
    for(ll i = 0; i <= max_pizza * 2; i += 2) {
        int tmp_x, tmp_y;
        if(x - i / 2 < 0)
            tmp_x = 0;
        else
            tmp_x = x - i / 2;

        if(y - i / 2 < 0)
            tmp_y = 0;
        else
            tmp_y = y - i / 2;
        cost = min(cost, tmp_x * a + tmp_y * b + c * i);
    }
    cout << cost << endl;
    return 0;
}