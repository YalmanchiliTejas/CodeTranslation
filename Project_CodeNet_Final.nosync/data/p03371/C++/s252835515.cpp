#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (c*2 >= a+b) {
        cout << x*a + y*b << endl;
    } else {
        int m = min(x, y);
        int cost = c*2*m;
        x -= m; y -= m;
        if (x > 0)
            cost += x * min(a, c*2);
        if (y > 0)
            cost += y * min(b, c*2);
        cout << cost << endl;
    }
    return 0;
}

