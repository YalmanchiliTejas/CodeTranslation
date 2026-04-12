#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    if(x % (y + z) < z) cout << x / (y + z) - 1 << endl;
    else cout << x / (y + z) << endl;
    return 0;
}