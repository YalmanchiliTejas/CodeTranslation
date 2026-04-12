#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    x -= z;
    cout << x / (y + z) << endl;
}