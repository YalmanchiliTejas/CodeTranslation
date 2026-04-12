#pragma region
#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define repc(i, m, n) for (int i = m; i < n; i++)
#define reprc(i, m, n) for (int i = m; i > n; i--)
#define all(v) v.begin(), v.end
#define INF 1e9
#define EPS 1e-10
using namespace std;
typedef long long ll;
#pragma endregion

int main()
{
    int A,B,C,X,Y,a,b,c,ans = INF;
    cin >> A >> B >> C >> X >> Y;

    C *= 2;

    rep(c, max(X,Y) + 1){
        a = 0;
        b = 0;
        if(c < X){
            a = X - c;
        }

        if(c < Y){
            b = Y - c;
        }

        ans = min(ans, c * C + a * A + B * b);
    }

    cout << ans << endl;
}

