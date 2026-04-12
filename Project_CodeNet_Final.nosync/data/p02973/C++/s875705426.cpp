#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    deque<int> d;

    rep(i, N)
    {
        int p = lower_bound(ALL(d), A[i]) - d.begin();
        int s = d.size();
        if (p == 0)
        {
            d.push_front(A[i]);
        }
        else
        {
            d[p - 1] = A[i];
        }
    }

    OP(d.size())

    return 0;
}