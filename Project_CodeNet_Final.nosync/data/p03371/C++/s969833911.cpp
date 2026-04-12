#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll count1,count2,count3;
    ll rem = max(x,y);
    count1 = 2 * rem * c;
    ll rem1 = min(x,y);
    ll chosen = (rem1 == x) ? 0 : 1;
    if (chosen == 0) {
        count2 = 2 * rem1 * c;
        ll diff = y - x;
        count2 += diff * b;
    } else {
        count2 = 2 * rem1 * c;
        ll diff = x - y;
        count2 += diff * a;
    }
    count3 = x * a + y * b;
    cout << min(count1,min(count2,count3)) << "\n";
}
