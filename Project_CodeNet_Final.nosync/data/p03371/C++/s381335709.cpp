#include <bits/stdc++.h>
using namespace std;

#define P(s) cout<<(s)<<"\n"
#define R(v) v.begin(),v.end()

int main() {
    int32_t a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    vector<int32_t> v{
        a * x + b * y,
        (x > y)
            ? (c * y * 2 + (x - y) * a)
            : (c * x * 2 + (y - x) * b),
        max(x, y) * 2 * c
    };

    P(*min_element(R(v)));
}