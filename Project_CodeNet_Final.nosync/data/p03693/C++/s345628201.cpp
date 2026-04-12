#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    z += y * 10 + x * 100;
    cout << (z % 4 ? "NO" : "YES") << endl;
}