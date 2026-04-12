#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll temp1 = 0;

    temp1 = a*x + b * y;

    if (x < y) {
        swap(x, y);
        swap(a, b);
    }

    ll temp2 = 0;
    temp2 = x*2*c;

    ll temp3 = 0;
    ll temp4 = 0;
    ll temp5 = 0;
    temp3 = y*2*c + (x -y)*a;
    temp4 = y*2*c + (x-y)*2*c;
    temp5 = y*2*c + (x-y)*2*c;

    temp3 = min(temp3, temp4);

    cout << min(temp3,min(temp1, temp2));
    //cout << temp1 << endl;
    //cout << temp2 << endl;
    //cout << temp3 << endl;



    return 0;
}
