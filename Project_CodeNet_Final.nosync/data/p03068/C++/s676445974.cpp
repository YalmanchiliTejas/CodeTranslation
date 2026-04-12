#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    string s;
    cin >> n >> s >> k;
    k--;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[k]) cout << s[i];
        else cout << "*";
    }
}
