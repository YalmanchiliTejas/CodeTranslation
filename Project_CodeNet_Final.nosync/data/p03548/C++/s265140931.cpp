#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9

typedef long long ll;

using namespace std;

const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 1e5+5;

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x, y, z;

    cin >> x >> y >> z;

    cout << x/(y+z)-(x%(y+z) < z);

    return 0;
}
