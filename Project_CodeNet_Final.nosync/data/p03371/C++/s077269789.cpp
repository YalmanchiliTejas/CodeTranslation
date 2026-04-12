#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int a, b, ab, x, y;
    cin >> a >> b >> ab >> x >> y;

    int minv = a*x + b*y;
    int sum = 2*ab*min(x, y);
    if (x > y) {
        sum += a*(x - y);
    } else if (x < y) {
        sum += b*(y - x);
    }
    minv = min(minv, sum);
    sum = 2*ab*max(x, y);
    minv = min(minv, sum);

    cout << minv << endl;




    return 0;
}