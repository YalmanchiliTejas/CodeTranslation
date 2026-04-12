#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++)
    {
        if (s[k - 1] == s[i])
        {
            cout << s[k - 1];
        }
        else
        {
            cout << "*";
        }
    }
    cout << endl;
    return 0;
}