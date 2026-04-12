#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;
#define pow10(n) int(1e##n + n)

LL calc(vector<LL> &A, bool larger)
{
    deque<LL> dq;
    if (larger)
    {
        sort(A.begin(), A.end());
    }
    else
    {
        sort(A.begin(), A.end(), [](LL a, LL b) { return a > b; });
    }
    dq.push_back(A[0]);

    int l = 0;
    int r = A.size();
    bool turn_large = true;
    while (true)
    {
        if (turn_large)
        {
            if (l < r - 2)
            {
                dq.push_front(A[r - 1]);
                dq.push_back(A[r - 2]);
                r -= 2;
            }
            else
            {
                if (l < r - 1)
                    dq.push_front(A[r - 1]);

                break;
            }
        }
        else
        {
            if (l + 2 < r)
            {
                dq.push_front(A[l + 1]);
                dq.push_back(A[l + 2]);
                l += 2;
            }
            else
            {
                if (l + 1 < r)
                    dq.push_front(A[l + 1]);

                break;
            }
        }
        turn_large = !turn_large;
    }

    LL prev_a = dq.front();
    dq.pop_front();
    LL ans = 0;
    for (auto a : dq)
    {
        ans += abs(prev_a - a);
        prev_a = a;
    }
    return ans;
};

void solve()
{
    int N;
    cin >> N;
    LL ans_g = 0;
    vector<LL> A(N);

    REP0 (i, N)
    {
        cin >> A[i];
    }

    ans_g = calc(A, false);
    ans_g = max(ans_g, calc(A, true));

    std::cout << ans_g << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
