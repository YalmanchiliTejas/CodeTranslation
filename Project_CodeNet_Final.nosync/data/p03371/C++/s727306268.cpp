#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MAX3(a, b, c) ((a) > (MAX(b, c)) ? (a) : (MAX(b, c)))
#define MIN3(a, b, c) ((a) < (MIN(b, c)) ? (a) : (MIN(b, c)))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    int a, b, c;
    ll x, y;
    cin >> a >> b >> c >> x >> y;
    ll cost = 0;
    cost += min(x, y) * min(a + b, 2 * c);
    if (x > y) {
        cost += min(a, 2 * c) * (x - y);
    } else {
        cost += min(b, 2 * c) * (y - x);
    }
    cout << cost << endl;
    return 0;
}