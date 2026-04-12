#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cnt(26, INT_MAX);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        vector<int> cur_cnt(26);
        for (char c : s)
            ++cur_cnt[c - 'a'];

        for (int j = 0; j < 26; ++j)
            cnt[j] = min(cnt[j], cur_cnt[j]);
    }

    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < cnt[i]; ++j)
        {
            char tmp = 'a' + i;
            cout << tmp;
        }

    cout << '\n';

    return 0;
}