#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

string s;
int n, k;

int main()
{
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[k - 1])
            s[i] = '*';
    }
    cout << s << endl;
}