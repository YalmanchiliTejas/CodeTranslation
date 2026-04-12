#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if(a+b <= 2*c) {
        cout << x*a + y*b;
    }
    else {
        if(x <= y) {
            if(2*c <= b) {
                cout << 2*y*c;
            }
            else {
                cout << (y - x)*b + 2*x*c;
            }
        }
        else {
            if(2*c <= a) {
                cout << 2*x*c;
            }
            else {
                cout << (x - y)*a + 2*y*c;
            }
        }
    }

    cout << endl;
    return 0;
}