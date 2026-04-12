#include <bits/stdc++.h>

using namespace std;
struct CinInit
{
    CinInit()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(20);
    };
} CinInit;

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[k - 1])
            s[i] = '*';
    }

    cout << s << "\n";

    return 0;
}
