#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((b * 10 + c) % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}