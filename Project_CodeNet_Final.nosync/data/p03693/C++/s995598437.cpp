#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    int num = r * 100 + g * 10 + b;

    cout << (num % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}
