#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll X, Y, Z; cin >> X >> Y >> Z;
        X -= Z;
        ll ans = X / (Y+Z);
        cout << ans << endl;


}
