#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
#define FOR(i, b, e) for (int i = (b); i < (e); ++i)
#define FORQ(i, b, e) for (int i = (b); i <= (e); ++i)
#define REP(x, n) for (int x = 0; x < (n); ++x)

using namespace std;

int a, b, c;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a >> b >> c;

    if ((b * 10 + c) % 4 == 0)
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";
}