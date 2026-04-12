#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

ll keta(ll a, ll b)
{
    int num_a = 0, num_b = 0;
    while (a)
    {
        num_a++;
        a /= 10;
    }
    while (b)
    {
        num_b++;
        b /= 10;
    }
    return max(num_a, num_b);
}

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 1001001001;
    for (int i = 0; i < (max(X,Y)+1)*2; i++)
    {
        int cnt = C * i * 2 + A * max(X - i, 0) + B * max(Y - i, 0);
        ans = min(cnt, ans);
    }

    cout << ans << endl;

    return 0;
}