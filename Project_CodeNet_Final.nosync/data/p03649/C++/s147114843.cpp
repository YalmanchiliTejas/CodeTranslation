#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int _##i = (t), i = (f); i <= _##i; i++)
#define uptil(f, t, i)   for(int _##i = (t), i = (f); i <  _##i; i++)
#define downto(f, t, i)  for(int _##i = (t), i = (f); i >= _##i; i--)
#define downtil(f, t, i) for(int _##i = (t), i = (f); i >  _##i; i--)
typedef long double LD;
#define long long long

#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define ln << endl
#else
#define debug false
#define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '

#define lam [&]


signed main() { // long: 64bit
    if(!debug) {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }

    int N; scanf("%d", &N);
    vector<long> A(N);
    times(N, i) scanf("%lld", &A[i]);

    long ans = 0;
    while(not all_of(A.begin(), A.end(), lam(long x){ return x < N; })) {
        long op = 0;
        times(N, i) {
            long opd = A[i] / N;
            op += opd;
            A[i] = A[i] % N - opd;
        }
        times(N, i) A[i] += op;
        if(debug) { times(N, i) cout << A[i] sp; cout ln; }
        ans += op;
    }

    cout << ans ln;

    return 0;
}
