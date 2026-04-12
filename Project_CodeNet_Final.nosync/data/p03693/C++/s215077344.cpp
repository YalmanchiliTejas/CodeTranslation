#include <bits/stdc++.h>
using namespace std;

using ll =long long;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int r,g,b;
    cin >> r >> g >> b;
    if ((10*g+b)%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}