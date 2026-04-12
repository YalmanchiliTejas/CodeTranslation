#include <bits/stdc++.h>

#define db(x) cerr << #x ": " << (x) << '\n';

#define int long long

using namespace std;

typedef long long ll;

typedef long double ld;

const int oo = 1e18;

string cad;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cad;

    if(cad[0] == cad[1] && cad[1] == cad[2])cout << "No" << '\n';
    else cout << "Yes" << '\n';

    return 0;
}
