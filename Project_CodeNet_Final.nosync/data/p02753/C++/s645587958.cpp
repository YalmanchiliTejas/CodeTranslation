#include <bits/stdc++.h>
#define rd(x) getline(cin, x)
#define _itr ::iterator
#define optf ios_base::sync_with_stdio(0); cin.tie(0);
#define rdarr(x, y) for (ll i = 0; i < y; ++i) cin >> x[i];
#define frop freopen("INPUT.inp", "r", stdin)
#define frcl fclose(stdin)
#define X first
#define Y second

#define MaxN 1000007

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<pi, pi> pii;

string st;

void Solve()
{
    getline(cin, st);
    if (st == "AAA" || st == "BBB") cout << "No";
    else cout << "Yes";
}

int main()
{
    optf;
    Solve();
}
