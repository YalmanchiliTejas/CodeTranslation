#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x, y, z;
    cin >> x >> y >> z;
    int k = x / (y+z);
    int n = x % (y+z);
    if(n==z) {
        cout << k << endl;
    } else {
        cout << k-1 << endl;
    }
}