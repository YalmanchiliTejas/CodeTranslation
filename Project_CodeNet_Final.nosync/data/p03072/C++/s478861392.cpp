#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 端点を間違えないように気をつけること!
#define FOR(i, m, n) for (ll i = (ll)(m); i <= (ll)(n); i++)
#define RFOR(i, m, n) for (ll i = (ll)(m); i >= (ll)(n); i--)
// 割り算をするときは自作関数syou,amariを使うこと!
// 入力は変数を宣言した直後に入れること!

int main()
{
    ll N;
    cin >> N;
    ll count = 0;
    ll Max = 0;
    ll H[N + 1];
    FOR(i, 1, N)
    {
        cin >> H[i];
        if (Max <= H[i])
        {
            count++;
            Max = H[i];
        }
    }
    cout << count << endl;
}