#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    string s;
    cin >> s;
    rep(i, s.size() - 1)
    {
        if (s[i] == 'A' && s[i + 1] == 'C')
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    // end

    return 0;
}
