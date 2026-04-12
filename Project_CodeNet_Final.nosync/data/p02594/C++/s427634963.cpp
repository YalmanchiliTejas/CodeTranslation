#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string YES = "Yes";
const string NO = "No";

void solve(long long X)
{
    string ans;
    if (X >= 30)
        ans = YES;
    else
    {
        ans = NO;
    }
    cout << ans << endl;
}

signed main()
{
    long long X;
    scanf("%lld", &X);
    solve(X);
    return 0;
}
