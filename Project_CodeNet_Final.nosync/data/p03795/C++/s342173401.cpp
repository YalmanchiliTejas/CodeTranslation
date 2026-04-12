#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x, y;
    cin >> n;
    
    x = 800*n;
    y = 200 * (n/15);

    cout << x - y << endl;
    
    return 0;
}