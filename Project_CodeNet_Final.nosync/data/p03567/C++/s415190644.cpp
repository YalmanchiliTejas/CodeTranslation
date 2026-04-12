#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);

    int good = 0;
    string s;
    cin >> s;
    for (int i = 0; i + 1 < s.size(); ++i) {
        if (s[i] == 'A' && s[i + 1] == 'C')
            good = 1;
    }
    cout << (good ? "Yes" : "No");

    return 0;
}
