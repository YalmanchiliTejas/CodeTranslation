#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v.size()))

    int n;
    string s, t;

bool smaller(int l, int r, int L, int R) {
    if (r - l > R - L)
    {
        s.swap(t);
        bool res = smaller(L, R, l, r);
        s.swap(t);
        return res ^ 1;
    }
    int len = min(r - l, R - L);
    string A = s.substr(l, len);
    string B = t.substr(L, len);
    if (r - l == R - L)
        return A < B;
    if (A == B)
        return smaller(l, r, L + len, R);
    return A < B;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> s >> t;
    if (!smaller(0, sz(s), 0, sz(t)))
        s.swap(t);
    for (int i=n; i>=0; i--)
        if (1LL * i * sz(s) <= n && (n - 1LL * i * sz(s)) % sz(t) == 0)
        {
            for (int j=0; j<i; j++)
                cout << s;
            for (int j=0; j<(n - 1LL * i * sz(s)); j+= sz(t))
                cout << t;
            cout << "\n";
            return 0;
        }
    assert(0);
    return 0;
}
