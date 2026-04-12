#include <bits/stdc++.h>
#define REP(i, n) for (int i=0, i##_len=(n); i<i##_len; ++i)
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
using ll = long long;
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int A[M], B[M];
    REP(i, M) cin >> A[i] >> B[i];

    int pat[N];
    pat[0] = 1;
    iota(pat+1, pat+N, 2);

    int ret = 0;
    do
    {
        REP(i, N-1)
        {
            REP(j, M)
            {
                if (A[j] == pat[i] && B[j] == pat[i+1] ||
                    B[j] == pat[i] && A[j] == pat[i+1])
                {
                    goto esc1;
                }
            }
            goto esc2;
esc1:;
        }
        ++ret;
esc2:;
    }
    while (next_permutation(pat+1, pat+N));

    cout << ret << endl;
    return 0;
}