#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
typedef std::pair<int,int> ipair;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int acount=0, bcount=0, ccount=0;
    int min_pizza;
    min_pizza = min(x, y);
    if ((a+b)*min_pizza > c*min_pizza*2) {
        ccount += (min_pizza*2);
    } else {
        acount += min_pizza;
        bcount += min_pizza;
    }
    if (max(x, y) == x) {
        int rest_pizza;
        rest_pizza = max(x, y) - min(x, y);
        if (a > c*2) {
            ccount += rest_pizza*2;
        } else {
            acount += rest_pizza;
        }
    } else {
        int rest_pizza;
        rest_pizza = max(x, y) - min(x, y);
        if (b > c*2) {
            ccount += rest_pizza*2;
        } else {
            bcount += rest_pizza;
        }
    }
    int total;
    total = acount*a+bcount*b+ccount*c;
    cout << total << endl;


    return 0;
}
