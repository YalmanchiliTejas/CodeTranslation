#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int (i) = 0; (i) <(int)n; ++(i))
#define rep2(i,s,n) for(int (i) = (s); (i) <(int)(n); ++(i))

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll min_price = 10000000000000;
    
    for(int i = 0; ; i = i + 2) {
        if(i / 2 > max(x,y)) break;

        int price;
        if(x - i/2 < 0)       price = b*(y-i/2) + c*i;
        else if(y - i/2 < 0)  price = a*(x-i/2) + c*i;
        else                price = a*(x-i/2) + b*(y-i/2) + c*i;

        if(min_price > price) min_price = price;
    }
    cout << min_price << endl;



}