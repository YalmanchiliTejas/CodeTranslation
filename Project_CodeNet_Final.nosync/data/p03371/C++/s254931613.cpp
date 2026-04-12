#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans1 = a * x + b * y;
    ll ans2, ans3;
    if (x >= y) ans2 = c * 2 * y + a * (x - y), ans3 = c * 2 * x;
    else if (x < y) ans2 = c * 2 * x + b * (y - x), ans3 = c * 2 * y;

    cout << min({ans1, ans2, ans3}) << endl;

    return 0;
}