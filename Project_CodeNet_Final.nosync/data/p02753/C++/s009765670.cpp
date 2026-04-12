#include <bits/stdc++.h>

#define ed cout << "\n";
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ffor(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(i, n) ffor(i, 0, n)
#define All(obj) (obj).begin(), (obj).end()
#define INF ((ll)1e9 + 7)
#define c(a) cout << a << "\n";
using namespace std;
const int N = 100005;
ll comb(ll a, ll b);
int main()
{
    speed;
    cout << fixed << setprecision(10);
    /*start*/
    set<char> a;
    rep(i, 3)
    {
        char b;
        cin >> b;
        a.insert(b);
    }
    if (a.size() == 2)
    {
        c("Yes");
    }
    else
    {
        c("No");
    }

    return 0;
}
