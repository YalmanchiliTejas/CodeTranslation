#include <bits/stdc++.h>

#define float double
#define debug(x)// (cerr << #x << ": " << (x) << endl)

typedef long long ll;

#define int ll

using namespace std;

int32_t main() {

    int a, b, ab, x, y;
    cin >> a >> b >> ab >> x >> y;

    ll totalSum = 0;

    if(2 * ab < a + b){
        // fill with half pizzas

        totalSum += min(x, y) * ab * 2;
        debug(totalSum);

        ll m = min(x, y);
        x -= m;
        y -= m;
    }
    else{
        totalSum += min(x, y) * a;
        totalSum += min(x, y) * b;

          ll m = min(x, y);
        x -= m;
        y -= m;
    }

    debug(x);
    debug(y);

    // rest:
    int rest = max(x, y);
    int restPrice = -1;
    if(rest == x){
        restPrice = a;
    }else{
        restPrice = b;
    }

    debug(restPrice);
    debug(rest);
    debug(ab);


    if( restPrice < 2 * ab){
        // fill with restprice
        totalSum += restPrice * rest;
    }
    else{
        debug(ab * rest* 2);
        totalSum += ab * rest* 2;
    }

    cout << totalSum << endl;

}
