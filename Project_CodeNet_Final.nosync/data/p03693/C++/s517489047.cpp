#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = a*100 + b*10 + c;
        if (ans % 4 == 0) {
                cout << "YES" << endl;
        }
        else cout << "NO" << endl;


}
