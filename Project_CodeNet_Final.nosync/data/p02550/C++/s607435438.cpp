#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

#define MOD 1000000007
#define PI 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

void solve1()
{
    ll n, x, m; cin >> n >> x >> m;
    ll tmp = x;
    ll sum = 0;
    set<ll> s;
    ll res = x;
    ll lo = 0;
    ll loc = 0;
    vector<ll> a;
    while(loc < n) {
        if(s.find(x) != s.end()) {
            res = x;
            break;
        }
        a.push_back(x);
        sum += x;
        s.insert(x);
        x *= x;
        x %= m;
        loc ++;
    }

    ll restn = n - loc;
    ll lom = 0;
    x = tmp;
    lo = sum;
    while(x != res) {
        lo -= x;
        x *= x;
        x %= m;
        lom ++;
    }

    loc -= lom;

    sum += floor(1.0*restn / loc)*lo;
    ll resm = restn%loc;
    ll by = min(lom + resm, (ll)a.size());
    for (int i = lom; i < by; i++)
    {
        sum += a[i];
    }


    cout << sum << endl;
}

int main()
{
    solve1();
}
