#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    auto min_counts = array<int, 26>{};
    min_counts.fill(numeric_limits<int>::max());

    for (auto i = 0; i < n; i++)
    {
        string s; cin >> s;

        auto counts = array<int, 26>{};
        for (const auto c : s)
            counts[c-'a']++;

        for (auto i = 0; i < 26; i++)
            min_counts[i] = min(min_counts[i], counts[i]);
    }

    for (auto i = 0; i < 26; i++)
        for (auto j = 0; j < min_counts[i]; j++)
            cout << char('a'+i);
    cout << endl;
}
