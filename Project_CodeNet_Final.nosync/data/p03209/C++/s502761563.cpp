#include <iostream>
#define ll long long
using namespace std;

ll ys[51];
ll ps[51];

ll ans = 0;

void solve(int n, ll x)
{
    if (x == 0 && n == 0) ++ans;
    if (x ==       0) return;
    if (x == ys[n]-1) { ans += ps[n]; return; }
    if (x == ys[n]/2) { ans += ps[n-1]+1; return; }

    if (x >= ys[n]/2) { ans += ps[n-1]+1; solve(n-1, x-ys[n-1]-2); return; }
    
    solve(n-1, x-1);
}

int main()
{
    int N;
    ll  X;
    cin >> N;
    cin >> X;

    ys[0] = 1;
    for (int i=1; i<=N; ++i) ys[i] = ys[i-1]*2+3;

    ps[0] = 1;
    for (int i=1; i<=N; ++i) ps[i] = ps[i-1]*2+1;

    solve(N, X-1);

    cout << ans << endl;
    return 0;
}
