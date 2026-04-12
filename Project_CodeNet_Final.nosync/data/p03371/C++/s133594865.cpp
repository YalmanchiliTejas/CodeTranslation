#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int res = INF;
    for (int i = 0; i <= max(x, y); ++i) {
        int tmp = 0;
        tmp += 2 * i * c;
        if (x >= i){
            tmp += (x-i) * a;
        }
        if (y >= i){
            tmp += (y-i) * b;
        }
        res = min(res, tmp);
    }
    cout << res << endl;
}