#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;
    char t = s[k - 1];
    rep(i, n)
    {
        if (s[i] != t)
            s[i] = '*';
    }
    cout << s << endl;
    return 0;
}
