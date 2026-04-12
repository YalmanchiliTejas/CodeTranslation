#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;


    // i is number of pizzas C.
    int i = 0;
    // l is number of pizzas A, m  is number of pizzas B.
    int l = 0, m = 0;
    int cnt = 1;
    int priceP = 0;
    int price = pow(10, 9);

    while(i/2 <= max(x, y)) {
        if (i % 2 == 0) {
            if (x-i/2 > 0) {
                l = x - i/2;
            } else {
                l = 0;
            }
            if (y-i/2 > 0) {
                m = y - i/2;
            } else {
                m = 0;
            }
            priceP = l * a + m * b + i * c;
            price = min(price, priceP);
        }
        i++;
    }
    cout << price << endl;
}