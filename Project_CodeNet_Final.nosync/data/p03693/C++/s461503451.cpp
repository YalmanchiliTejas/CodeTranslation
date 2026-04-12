#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int res = 100*r + 10*g + b;
    if(res%4) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}