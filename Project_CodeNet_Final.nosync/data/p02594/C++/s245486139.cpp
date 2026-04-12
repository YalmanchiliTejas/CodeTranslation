#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
const ll N = 1e6 + 5;
const ll maxn = 5005;
ll m, n, t, T, k, a[N], b[N];
string s, ss;
struct dang
{
    ll pos, val, mn, mx, vtri;
};
bool so(const dang& x, const dang& y)
{
    return (x.val < y.val) || (x.val == y.val && x.pos < y.pos);
}
void sol()
{
    cin >> n;
    if(n >= 30)
    cout << "Yes";
    else cout << "No";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cin >> T; while(T -- > 0)
    sol();
}
