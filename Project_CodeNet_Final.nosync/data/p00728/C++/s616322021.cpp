#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vll = vector<ll>;
using vvll = vector<vll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
using plli = pair<ll, int>;
using vplli = vector<pair<ll, int>>;
using pllll = pair<ll, ll>;
using vpllll = vector<pair<ll, ll>>;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)
//試験導入
#define irep(i, end_i, begin_i) for (ll i = (ll)begin_i - 1; i >= (ll)end_i; i--)

long long INF = 1LL << 60;
int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        ll res = 0;
        int max = -(1 << 30), min = 1 << 30;
        rep(i, 0, n)
        {
            int s;
            cin >> s;
            res += s;
            chmax(max, s);
            chmin(min, s);
        }
        cout << (res - max - min) / (n - 2) << endl;
    }
    return 0;
}

