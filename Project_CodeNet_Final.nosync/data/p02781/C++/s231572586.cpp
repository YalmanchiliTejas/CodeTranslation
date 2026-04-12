#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i<(b); ++i)
#define RFOR(i, b, a) for (int i = (b)-1; i>=(a); --i)
#define FILL(a, b) memset(a, b, sizeof(a))

void dout() { cerr << endl; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

string s;

LL solve(int last, bool less, int cnt)
{
    if (cnt == 1)
        return 1;
    LL ans = 0;
    int b = 1;
    bool nz = false;
    FOR(nxt, last + 1, SZ(s))
    {
        if (!less && s[nxt] == '0' && !nz)
        {
            b++;
            continue;
        }
        else
        {
            nz = true;
        }
        if (nxt != last + b || less)
        {
            ans += solve(nxt, true, cnt - 1) * 9;
        }
        else
        {
            ans += solve(nxt, false, cnt - 1);
            ans += solve(nxt, true, cnt - 1) * (s[nxt] - '1');
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> s >> k;
    LL ans = 0;
    FOR(i, 0, SZ(s))
    {
        if (i != 0)
            ans += solve(i, true, k) * 9;
        else
        {
            ans += solve(i, false, k);
            ans += solve(i, true, k) * (s[0] - '1');
        }
    }
    cout << ans << "\n";
    return 0;
}