#include <bits/stdc++.h>
#define REP(i, n) for (int i=0, i##_len=(n); i<i##_len; ++i)
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
using ll = long long;
using namespace std;

int main()
{
    int N;
    cin >> N;
    int H[N];
    REP(i, N) cin >> H[i];

    int ret = 1;
    FOR(i, 1, N)
    {
        bool ok = true;
        REP(j, i)
        {
            if (H[j] > H[i]) ok = false;
        }

        if (ok) ++ret;
    }

    cout << ret << endl;
    return 0;
}
