#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    int N;
    cin >> N;
    int div = N / 15;
    ll ans = 800 * N - div * 200;
    cout << ans << endl;
}