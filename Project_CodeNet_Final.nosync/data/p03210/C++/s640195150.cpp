#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main()
{
    int d;
    cin >> d;
    string ans = "NO";
    if (d == 3 || d == 5 || d == 7)
        ans = "YES";
    cout << ans << endl;
    return 0;
}