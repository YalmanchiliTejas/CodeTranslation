#include <bits/stdc++.h>
#include <cstring>
#include <limits>
using namespace std;
#define ll long long int
#define lli long long int
#define fw(i, s, e) for (ll i = s; i < e; ++i)
#define fe(i, s, e) for (ll i = s; i <= e; ++i)
#define fb(i, e, s) for (ll i = e; i >= s; --i)
#define L(T)  \
    ll T;     \
    cin >> T; \
    while (T--)
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define mem(a, i) memset(a, i, sizeof(a))
#define ld long double
#define endl "\n"
#define in(P) \
    ll P;     \
    cin >> P;
int main()
{
    FASTIO
    // L(T)
    {
        // char s[45];
        string s;
        cin >> s;
        if (s == "AAA")
        {
            cout << "No" << endl;
        }
        else if (s == "BBB")
            cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}