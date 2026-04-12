#include <bits/stdc++.h>

using ll = long long;

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF (1 << 29)

using namespace std;

//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    int ans = (x - z) / (y+z);
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
