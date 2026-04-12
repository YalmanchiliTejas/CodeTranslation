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
    int n, m, x, y;
    cin >> n;
    m = n/15;
    x = 800*n;
    y = 200*m;
    cout << x-y;

    cout << endl;
    return 0;
}