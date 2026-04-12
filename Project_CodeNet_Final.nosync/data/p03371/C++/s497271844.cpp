#include <bits/stdc++.h>
#include <cxxabi.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

char *demangle(const char *demangle)
{
    int status;
    return abi::__cxa_demangle(demangle, 0, 0, &status);
}

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 1001001001;
    for (int i = 0; i < (max(X, Y) + 1) * 2; i++)
    {
        int cnt = A * max(0, X - i) + B * max(0, Y - i) + C * i * 2;
        ans = min(cnt, ans);
    }
    cout << ans << endl;

    return 0;
}
