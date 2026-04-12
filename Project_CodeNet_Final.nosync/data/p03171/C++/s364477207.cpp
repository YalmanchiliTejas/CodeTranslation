#include <algorithm>
#include <iostream>

using namespace std;
using ll       = long long;
const int NMAX = 3e3 + 11;

int  n, a[NMAX], li, ri;
ll   mem[NMAX][NMAX];
bool vis[NMAX][NMAX];

ll solve(bool maximizer)
{
    int l, r;
    ll  left_ans, right_ans;

    if (li > ri)
        return 0;

    ll &ans = mem[li][ri];
    if (vis[li][ri])
        return ans;
    vis[li][ri] = true;

    l        = a[li++];           // try
    left_ans = solve(!maximizer); // partial ans
    --li;                         // undo

    r         = a[ri--];           // try
    right_ans = solve(!maximizer); // partial ans
    ++ri;                          // undo

    if (maximizer)
        ans = max(l + left_ans, r + right_ans);
    else
        ans = min(left_ans - l, right_ans - r);
    return ans;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    li = 0, ri = n - 1;

    cout << solve(true) << endl;
    return 0;
}
