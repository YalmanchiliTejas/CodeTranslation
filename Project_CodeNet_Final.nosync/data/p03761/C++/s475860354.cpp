#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main()
{
    ios_base::sync_with_stdio(0);

    int n; cin >> n;

    vi v(256, INT_MAX);

    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;

        vi w(256, 0);

        for(auto x : s) w[x]++;

        for(int j = 0; j < 256; j++)
            v[j] = min(v[j], w[j]);
    }

    for(int i = 0; i < 256; i++)
    for(int j = 0; j < v[i]; j++)
        cout << char(i);

    cout << endl;
    return 0;
}