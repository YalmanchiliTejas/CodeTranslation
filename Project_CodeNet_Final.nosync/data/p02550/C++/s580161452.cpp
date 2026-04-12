/*COMPETITIVE PROGRAMMING C++ TEMPLATE */

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <iomanip>

#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n"
#define MOD 998244353

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

void solve()
{
    ll n, x, m;
    cin >> n >> x >> m;

    vector<ll> a;
    set<ll> S;

    ll r = 0;

    for(int i = 0; i < n; i++)
    {
        if(S.find(x % m) != S.end())
        {
            r = x % m;
            break;
        }
        else {
            S.insert(x % m);
            a.push_back(x % m);
            x *= x;
            x %= m;
        }
    }

    int pos = 0;
    ll ans = 0;

    while(pos < a.size())
    {
        if(a[pos] == r)
        {
            break;
        }
        ans += a[pos];
        pos++;
        n--;
    }

    int p = pos;

    ll sum = 0;
    ll N = a.size() - pos;
    while(pos < a.size())
    {
        sum += a[pos];
        pos++;
    }

    if(N == 0)
    {
        cout << ans << "\n";
        return;
    }

    ans += sum * (n / N);

    for(int i = 0; i < n % N; i++)
    {
        ans += a[p + i];
    }


    cout << ans << "\n";




    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    //cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}



